#include <bits/stdc++.h>
using namespace std;

int dl[] = { 0, 1,  1,  0, -1, -1 },
	dc[] = { 1, 0, -1, -1,  0,  1 };

int R, C;
char grid[110][110];
char gamb[2] = { '(', ')' };

void ff2(int r, int c) {
	if (r < 0 || r >= R || c < 0 || c >= C) return;
	if (grid[r][c] == '.' || grid[r][c] == 'B') return;
	grid[r][c] = 'B';
	for (int k = 0; k < 6; ++k) ff2(r + dl[k], c + dc[k]);
}

void ff1(int r, int c, bool c2) {
	if (r < 0 || r >= R || c < 0 || c >= C) return;
	if (grid[r][c] != '*' && grid[r][c] != 'I') return;

	if (grid[r][c] == '*')
		grid[r][c] = gamb[c2];
	else if (grid[r][c] == 'I')
		grid[r][c] = '(';
	
	for (int k = 0; k < 6; ++k) ff1(r + dl[k], c + dc[k], !c2);

	for (int k = 0; k < 6; ++k) {
		int x = r + dl[k],
			y = c + dc[k];

		if (x >= 0 && x < R && y >= 0 && y < C)
			if (grid[x][y] == grid[r][c])
				ff2(r, c);
	}
}

void ff3(int r, int c) {
	if (r < 0 || r >= R || c < 0 || c >= C) return;
	if (grid[r][c] != '*') return;
	grid[r][c] = 'F';
	for (int k = 0; k < 6; ++k) ff3(r + dl[k], c + dc[k]);
}

int main()
{
	while (scanf("%d %d\n", &R, &C) && R) {
		scanf("%d %d\n", &R, &C);
		for (int i = 0; i < R; ++i) scanf("%s\n", grid[i]);

		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
				if (grid[i][j] == 'I')
					ff1(i, j, false);

		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
				if (grid[i][j] == '*')
					ff3(i, j);

		printf("\n");

		for (int i = 0; i < R; ++i)
			printf("%s\n", grid[i]);
	}
}
