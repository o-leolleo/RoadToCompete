#include <bits/stdc++.h>
using namespace std;
#define MAX 110
char grid[MAX][MAX];
bool gl[MAX], gc[MAX];
int N, dl[] = {1, -1, -1,  1},
       dc[] = {1,  1, -1, -1};

int dfs(int l, int c, int c1, int c2)
{
	if (l < 0 || l >= N || c < 0 || c >= N) return 0;
	if (grid[l][c] != c1) return 0;
	grid[l][c] = c2;
	int ans;
	if (!gl[l] && !gc[c]) {
		gl[l] = gc[c] = true;
		ans = 1;
	} else
		ans = 0;

	for (int d = 0; d < 4; ++d)
		ans += dfs(l + dl[d], c + dc[d], c1, c2);
	return ans;
}

int main()
{
	while (scanf("%d\n", &N) != EOF) {
		int stl, stc; stl = stc = -1;

		memset(gl, false, sizeof gl);
		memset(gc, false, sizeof gc);

		for (int a = 0; a < N; ++a)
			for (int b = 0; b < N; ++b) {
				scanf("%c\n", &grid[a][b]);
				if (stl < 0 && grid[a][b] == '.') {
					stl = a;
					stc = b;
				}
			}
			

		if (stl >= 0) printf("%d\n", dfs(stl, stc, '.', '#'));
		else printf("0\n");

		for (int l = 0; l < N; ++l)
		{
			for (int c = 0; c < N; ++c)
				printf("%c", grid[l][c]);
			printf("\n");
		}
	}
}
