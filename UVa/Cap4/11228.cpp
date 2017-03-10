#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
double roads, railroads;
int states;
vector< pll > vert;
vector< pair<double, ii> > edgeList;

class UnionFind {
private: vector<int> p, rank;
public:
	UnionFind(int N) { p.assign(N, 0); rank.assign(N, 0);
		for (int i = 0; i < p.size(); ++i) p[i] = i;
	}
	int findSet(int i) { return (i == p[i]) ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) {
				p[y] = x;
			} else {
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}

};

double dist(pll x, pll y) {
	return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}


int main()
{
	int T;
	scanf("%d\n", &T);

	for (int c = 1; c <= T; ++c) {
		int n;
		ll mst_cost = 0, r;

		scanf("%d %lld\n", &n, &r);

		roads = railroads = 0;
		states = 1;
		
		UnionFind UF(n);

		while (n--) {
			int x, y; scanf("%d %d\n", &x, &y);
			vert.push_back(make_pair(x, y));
		}

	
		for (int i = 0; i < vert.size(); ++i)
			for (int j = i + 1; j < vert.size(); ++j)
				edgeList.push_back(make_pair(dist(vert[i], vert[j]), make_pair(i, j)));	

		sort(edgeList.begin(), edgeList.end());

		for (int i = 0; i < edgeList.size(); ++i) {
			pair< double, ii > front = edgeList[i];

			if (!UF.isSameSet(front.second.first, front.second.second)) {
				if (front.first <= r)
					roads += front.first;
				else {
					railroads += front.first;
					states++;
				}

				UF.unionSet(front.second.first, front.second.second);
			}
		}

		printf("Case #%d: %d %lld %lld\n", c, states, (ll)round(roads), (ll)round(railroads));
		edgeList.clear();
		vert.clear();
	}
}
