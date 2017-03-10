#include <bits/stdc++.h>
using namespace std;
char grid[15][15];

int dr[] = {-1, 0, 1, 0},
	dc[] = { 0,-1, 0, 1};


int ff(int r, int c, char c1, char c2)
{
	if (r < 0 || r >= 9 || c < 0 || c >= 9) return 0;
	if (grid[r][c] != c1) return grid[r][c] == '.';
	grid[r][c] = c2;
	int ans = 0;
	for (int k = 0; k < 4; ++k)
		ans += ff(r + dr[k], c + dc[k], c1, c2);

	return ans;
}

int main()
{
	int T; scanf("%d\n", &T);

	for (int c = 1; c <= T; ++c) {
		for (int l = 0; l < 9; ++l)
			scanf("%s\n", grid[l]);

		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				if (grid[i][j] == 'x' && !ff(i, j, 'x', '#'))
					ff(i, j, '#', '.');
				else if (grid[i][j] == '#')
					ff(i, j, '#', 'x');

		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				if (grid[i][j] == 'o' && !ff(i, j, 'o', '#'))
					ff(i, j, '#', '.');
				else if (grid[i][j] == '#')
					ff(i, j, '#', 'o');

		int i, j;

		for (i = 0; i < 9; ++i)
			for (j = 0; j < 9; ++j)
				if ((grid[i][j] == 'o') && (ff(i, j, 'o', '#') == 1))
					i = j = 9;

		printf("Case #%d: ", c);

		if (i == 9 && j == 9)
			printf("Can not kill in one move!!!\n");
		else
			printf("Can kill in one move!!!\n");
	}
}
