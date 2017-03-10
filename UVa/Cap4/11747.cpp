#include<bits/stdc++.h>
using namespace std;

class UnionFind {
private: vector<int> p, rank;
public:
		UnionFind(int N) {
			 rank.assign(N, 0);
			 p.assign(N, 0);
			 for (int i = 0; i < N; ++i) p[i] = i;
		}

		int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
		int isSameSet(int i, int j) { return findSet(i) == findSet(j); }
		void unionSet(int i, int j) {
			if (!isSameSet(i, j)) {
				int x = findSet(i),
					y = findSet(j);

				if (rank[x] > rank[y]) p[y] = x;
				else {
					p[x] = y;
					if (rank[x] == rank[y])
						rank[y]++;
				}
			}
		}
};

typedef pair<int, int> ii;
vector< pair< int, ii > > EdgeList;

int main()
{
	int n, m;

	while (scanf("%d %d\n", &n, &m) && (n || m)) {
		while (m--) {
			int u, v, w; scanf("%d %d %d\n", &u, &v, &w);
			EdgeList.push_back(make_pair(w, ii(u, v)));
		}

		sort(EdgeList.begin(), EdgeList.end());

		bool forest = true;
		UnionFind UF(n);
		
		for (int i = 0; i < EdgeList.size(); ++i) {
			pair< int, ii > front = EdgeList[i];

			if (!UF.isSameSet(front.second.first, front.second.second)) {
				UF.unionSet(front.second.first, front.second.second);
			} else {
				if (!forest)
					printf(" ");
				
				printf("%d", front.first);
				forest = false;
			}
		}
	
		if (forest)
			printf("forest\n");
		else
			printf("\n");

		EdgeList.clear();
	}
}
