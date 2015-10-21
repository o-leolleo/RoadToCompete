#include <bits/stdc++.h>
using namespace std;
char grid[15][20];

int dl[] = {1, 0, -1,  0},
    dc[] = {0, 1,  0, -1},
    C = 15;

int dfs(int l, int c, char c1, char c2)
{
	if(l < 0 || l >= 10 || c < 0 || c >= C) return 0;
	if (grid[l][c] != c1) return 0;
	grid[l][c] = c2;
	int ans = 1;
	for (int k = 0; k < 4; ++k)
		ans += dfs(l + dl[k], c + dc[k], c1, c2);
	return ans;
}

void shift_up()
{
	for (int j = 0; j < C; ++j) {
		int top = 0;
		for (int i = 0; i < 10; ++i)
			if (grid[i][j] != '.') grid[top++][j] = grid[i][j];
		for (int i = top; i < 10; ++i) grid[i][j] = '.';
	}
}

void shift_left()
{
	int col = 0;
	for (int j = 0; j < C; ++j) {
                int i;
		for (i = 0; i < 10; ++i) if (grid[i][j] != '.') break;
		if (i == 10) col |= (1 << j);
	}
	int top;
	for (int i = 0; i < 10; ++i) {
		top = 0;
		for (int j = 0; j < C; ++j)
			if (!(col & (1 << j))) grid[i][top++] = grid[i][j];
	}

	C = top;
}

int main()
{
	int T;
        bool sta = false, id[300];
	char c1[] = {'R', 'G', 'B'}, c2[] = {'r', 'g', 'b'};

        scanf("%d\n", &T);

        for (int game = 1; game <= T; ++game) {
		C = 15;
                if (sta) printf("\n");
                printf("Game %d:\n\n", game);

                for (int l = 0; l < 10; ++l) scanf("%s\n", grid[9 - l]);

		int maior, sl, sc, score = 0, move = 0, rem;
                char type;

		do {
			maior = 0; rem = 0;
			for (int c = 0; c < C; ++c)
                                for (int l = 0; l < 10; ++l) {
                                        int ch;
                                        for (ch = 0; ch < 3; ++ch)
                                                if (grid[l][c] == c1[ch]) break;

        				if (ch < 3) {
        					int p = dfs(l, c, c1[ch], c2[ch]);
        					if (p > maior) {
        						maior = p; sl = l; sc = c;
                                                        type = toupper(c1[ch]);
        					}
                                                rem += p;
        				}
                                }

                        for (int p = 0; p < 3; ++p) {
                                char tmp = c2[p];
                                c2[p] = c1[p];
                                c1[p] = tmp;
                        }

			if (maior > 1) {
                                int tmp = (maior - 2) * (maior - 2);
				dfs(sl, sc, grid[sl][sc], '.');
				shift_up();
                                shift_left();
                                printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n", ++move, sl + 1, sc + 1, maior, type, tmp);
                                score += tmp;
			}
		} while(maior > 1);

		if (islower(c1[0]))
			for (int p = 0; p < 3; ++p) {
				char tmp = c2[p];
				c2[p] = c1[p];
				c1[p] = tmp;
			}

                printf("Final score: %d, with %d balls remaining.\n", rem ? score : score + 1000, rem);
                sta = true;
	}
}
