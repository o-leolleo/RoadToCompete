#include <bits/stdc++.h>
using namespace std;
int dfs_num[50100];
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
vvi Adj;

int dfs(int u, int color)
{
	int sum = 0;
	dfs_num[u] = color;
	for (int i = 0; i < (int) Adj[u].size(); ++i) {
		int v = Adj[u][i];
		if (dfs_num[v] != color)
			sum += dfs(v, color);
	}
	return sum + 1;
}

int main()
{
	int T, N; scanf("%d\n", &T);

	for (int c = 1; c <= T; ++c) {
		scanf("%d\n", &N);
		Adj.assign(N + 1, vi());

		for (int i = 0; i < N; ++i) {
			int a, b;
			scanf("%d %d\n", &a, &b);
			Adj[a].push_back(b);
		}

		memset(dfs_num, 0, sizeof dfs_num);
		int mm = -1, theGuy;

		for (int v = 1; v <= N; ++v)
			if (dfs_num[v] == 0) {
				int p = dfs(v, v);
				if (p > mm) {
					mm = p;
					theGuy = v;
				}
			}

		printf("Case %d: %d\n", c, theGuy);
	}
}
