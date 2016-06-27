#include <bits/stdc++.h>
#define MAX 999999999
using namespace std;
int N, M, I, age[510];
bool A[510][510];
int d[510];

int dfs(int u, int v)
{
	d[u] = MAX;

	if (u == v) return MAX;

	for (int i = 0; i < N; ++i) {
		if (A[u][i] && d[i] < 0)
			d[u] = min(d[u], dfs(i,v));
		
		if (A[u][i] && i == v)
			d[u] = min(d[u], age[u]);
		else if (A[u][i] && d[i] != MAX)
			d[u] = min(d[u], d[i]);
	}

	if (d[u] != MAX) d[u] = min(d[u], age[u]);
	return d[u];
}

int main()
{
	while (scanf("%d %d %d\n", &N, &M, &I) != EOF) {
		for (int i = 0; i < N; ++i)
			scanf("%d", &age[i]);

		memset(A, 0, sizeof A);

		for (int i = 0; i < M; ++i) {
			int x, y;
			scanf("%d %d\n", &x, &y);
			x--; y--;
			A[x][y] = 1;
		}

		while (I--) {
			char t; int a, b;
			scanf("%c\n", &t);

			if (t == 'T') {
				scanf("%d %d\n", &a, &b);
				a--, b--;
				for (int i = 0; i < N; ++i) swap(A[a][i], A[b][i]);
				for (int i = 0; i < N; ++i) swap(A[i][a], A[i][b]);
			} else {
				scanf("%d\n", &a); a--;
				for (int i = 0; i < N; ++i) d[i] = -1;
				int jovem = MAX;

				for (int i = 0; i < N; ++i)
					if (i != a && d[i] < 0) jovem = min(jovem, dfs(i,a));

				if (jovem != MAX)
					printf("%d\n", jovem);
				else
					printf("*\n");
			}
		}
	}
}
