#include <bits/stdc++.h>
using namespace std;
int T, n, r;
typedef pair<int, int> ii;
pair<int, int> node;
pair< int, ii > EL;
int dist(ii a, ii b) { return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second); }

class UnionFind {
private: vector<int> p, rank;
public:
	 UnionFind(int N) {
		 rank.assign(N, 0);
		 p.assign(N, 0);
		 for (int i = 0; i < N; ++i) p[i] = i; 
	 }

	 int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
	 bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
	 void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) p[y] = x;
			else {
				p[y] = x;
				p[x] = y;
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	 }
};

int main()
{
	scanf("%d %d %d\n", &T, &n, &r);

	while (T--) {
		int x, y;
		for (int i = 0; i < n; ++i) {
			scanf("%d %d\n", &x, &y);
			node[i].first = x;
			node[i].second = y;
		}

		for (int i = 0; i < n; ++i)
			for (int j = i+1; j < n; ++j)
				EL.push_back(pair< int, ii >(dist(node[i],node[j]), ii(i, j)));

		sort(EL.begin(), EL.end());		
		int mst1, mst2; mst1 = mst2 = 0;
		UnionFind UF(n);
		
		for (int i = 0; i < EL.size(); ++i) {
			pair<int, ii> front = EL[i];
			if (!UF.isSameSet(front.second.first, front.second.second)) {
				if (front.first <= r) mst1 += front.first;
				else mst2 += front.first;
			}
		}
	}
}
