#include<bits/stdc++.h>
using namespace std;

int dl[] = {1, 0, -1, 0},
    dc[] = {0, 1,  0, -1};

typedef long long ll;
#define MAX 110
bool vis[MAX][MAX];
ll grid[MAX][MAX];
int R, C;

void dfs(int x, int y, ll c)
{
	if (x < 0 || x >= R || y < 0 || y >= C) return;
	if (vis[x][y] || grid[x][y] != c) return;

	vis[x][y] = true;

	for (int i = 0; i < 4; ++i)
		dfs(x + dl[i], y + dc[i], c);
}

int main()
{
	scanf("%d %d\n", &R, &C);

	for (int r = 0; r < R; ++r)
		for (int c = 0; c < C; ++c)
			scanf("%lld\n", &grid[r][c]);

	memset(vis, false, sizeof vis);

	ll up = 0;

	for (int r = 0; r < R; ++r)
		for (int c = 0; c < C; ++c)
			if (!vis[r][c]) { dfs(r, c, grid[r][c]); up++; }

	ll lat = 0;

	for (int r = 0; r < R - 1; ++r)
		for (int c = 0; c < C; ++c) {
			if (c > 0) {
				int x = grid[r+1][c], y = grid[r+1][c-1], w = grid[r][c], z = grid[r][c-1];
				
				while (c < C &&  ((x > w && y > z && y > w && x > z) || (x < w && y < z && x < z && y < w))) {
					c++;

					if (c < C) {
						x = grid[r+1][c]; y = grid[r+1][c-1]; w = grid[r][c]; z = grid[r][c-1];
					}
				}
			}

			if (c < C && grid[r][c] != grid[r+1][c]) lat++;
		}

	for (int c = 0; c < C - 1; ++c) 
		for (int r = 0; r < R; ++r) {
			if (r > 0) {
				int x = grid[r][c+1], y = grid[r-1][c+1], w = grid[r][c], z = grid[r-1][c];

				while (r < R &&  ((x > w && y > z && y > w && x > z) || (x < w && y < z && x < z && y < w))) {
					r++;

					if (r < R) {
						x = grid[r][c+1]; y = grid[r-1][c+1]; w = grid[r][c]; z = grid[r-1][c];
					}
				}
			}

			if (r < R && grid[r][c] != grid[r][c+1]) lat++;
		}


	printf("%lld\n", lat + up + 5);
}

