#include <bits/stdc++.h>
using namespace std;
char grid[220][520];
int dr[] = {1, 0, -1,  0},
    dc[] = {0, 1,  0, -1},
    H, W;

int white_explorer(int r, int c)
{
        if (r < 0 || r > H || c < 0 || c > W) return 0;
        if (grid[r][c] == '#') return 0;
        if (grid[r][c] == 'B' || grid[r][c] == '1' || grid[r][c] == 'W') return 1;
        grid[r][c] = 'W';
        int ans = 1;
        for (int d = 0; d < 4; ++d)
                ans = ans && white_explorer(r + dr[d], c + dc[d]);
        if (ans == 0) grid[r][c] = '#';
        return ans;
}

int black_explorer(int r, int c)
{
        if (r < 0 || r > H || c < 0 || c > W) return 0;
        if (grid[r][c] == 'B' || grid[r][c] == 'W' || grid[r][c] == '#') return 0;
        if (grid[r][c] == '0') return white_explorer(r, c);
        grid[r][c] = 'B';
        int sum = 0;
        for (int d = 0; d < 4; ++d)
                sum += black_explorer(r + dr[d], c + dc[d]);
        return sum;
}

int main()
{
	int a, b, c, caso = 0; char tmp, ans[10000];
	while (scanf("%d %d\n", &H, &W) && H) {
                memset(grid, '0', sizeof grid);
		for (a = 0; a < H; ++a)
			for (b = 0; b < W; ++b) {
				scanf("%c\n", &tmp);
				for (c = 0; c < 4; ++c) {
					if (tmp >= 'a' && tmp <= 'f')
						grid[a][b * 4 + c] = ((tmp - 'a' + 10) & (1 << (3 - c))) ? '1' : '0';
					else
						grid[a][b * 4 + c] = ((tmp - '0') & (1 << (3 - c))) ? '1' : '0';
				}
			}

		W *= 4;
                int tam = 0;
                for (a = 0; a < H; ++a)
                        for (b = 0; b < W; ++b) if (grid[a][b] == '1') {
                                int tmp = black_explorer(a, b);
                                if (tmp == 0) ans[tam++] = 'W';
                                else if (tmp == 1) ans[tam++] = 'A';
                                else if (tmp == 2) ans[tam++] = 'K';
                                else if (tmp == 3) ans[tam++] = 'J';
                                else if (tmp == 4) ans[tam++] = 'S';
                                else if (tmp == 5) ans[tam++] = 'D';
                        }

                sort(ans, ans + tam);
                ans[tam] = '\0';
                printf("Case %d: %s\n", ++caso, ans);
	}
}
