#include <bits/stdc++.h>
using namespace std;
int M, N, dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};
char grid[30][30], l;

int dfs(int r, int c)
{
	if (r > M || r < 0) return 0;
	if (c < 0) c += N;
	c %= N;
	if (grid[r][c] != l) return 0;
	grid[r][c] = l + 1;
	int ans = 1;
	for (int d = 0; d < 4; ++d)
		ans += dfs(r + dr[d], c + dc[d]);
	return ans;
}

int main()
{
	while (scanf("%d %d\n", &M, &N) != EOF) {
		for (int i = 0; i < M; ++i) scanf("%s\n", grid[i]);
		int x, y, maior = 0;
		scanf("%d %d\n", &x, &y);
		l = grid[x][y];
		dfs(x,y);
		for (int i = 0; i < M; ++i)
			for (int j = 0; j < N; ++j) if (grid[i][j] == l) {
				int c = dfs(i, j);
				maior = max(maior, c);
			}
		printf("%d\n", maior);
	}
}
