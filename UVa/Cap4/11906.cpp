#include <bits/stdc++.h>
using namespace std;
int dl[4], dc[4], T, R, C, M, N, W, forbidden;
char grid[110][110];
#define x(a) (a/C)
#define y(b) (b%C)
#define toNode(a, b)(a * C + b)

inline void dfs(int node)
{
	grid[x(node)][y(node)] = 'x';
	int sum = 0;

	for (int i = 0; i < 4; ++i)
		if (!(forbidden & (1 << i))) {
			int l = x(node) + dl[i], c = y(node) + dc[i];
			if (l < R && l >= 0 && c < C && c >= 0 && grid[l][c] != 'w') {
				sum++;

				if (grid[l][c] != 'x'
				 && grid[l][c] != 'e'
				 && grid[l][c] != 'o')
					dfs(toNode(l, c));
			}
		}

	if (N != M)
		for (int i = 0; i < 4; ++i) {
			if (!(forbidden & (1 << i))) {
				int l = x(node) + dc[i], c = y(node) + dl[i];
				if (l < R && l >= 0 && c < C && c >= 0 && grid[l][c] != 'w') {
					sum++;

					if (grid[l][c] != 'x'
					 && grid[l][c] != 'e'
					 && grid[l][c] != 'o')
						dfs(toNode(l, c));
				}
			}
		}

	if (sum % 2 == 0) grid[x(node)][y(node)] = 'e';
	else grid[x(node)][y(node)] = 'o';
}

int main()
{
	scanf("%d\n", &T);
	for (int c = 1; c <= T; ++c) {
		scanf("%d %d %d %d %d\n", &R, &C, &M, &N, &W);
		memset(grid, '.', sizeof grid);
		forbidden = 0;

		if (N == 0) forbidden |= ((1 << 2) | (1 << 3));
		else if (M == 0) forbidden |= ((1 << 1) | (1 << 3));

		dl[0] =  M; dc[0] =  N;
		dl[1] = -M; dc[1] =  N;
		dl[2] =  M; dc[2] = -N;
		dl[3] = -M; dc[3] = -N;

		while (W--) {
			int a, b; scanf("%d %d\n", &a, &b);
			grid[a][b] = 'w';
		}

		dfs(0);

		int odd, even; odd = even = 0;
		for (int i = 0; i < R; ++i) for (int j = 0; j < C; ++j)
			if (grid[i][j] == 'e') even++;
			else if(grid[i][j] == 'o') odd++;
		printf("Case %d: %d %d\n", c, even, odd);
	}
}
