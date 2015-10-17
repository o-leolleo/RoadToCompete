#include <bits/stdc++.h>
using namespace std;
char grid[110][110];
int N, dl[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};

int dfs(int l, int c)
{
	if (l < 0 || l > N || c < 0 || c > N) return 0;
	if (grid[l][c] != 'x' && grid[l][c] != '@') return 0;
	int ans = (int)(grid[l][c] == 'x');
	grid[l][c] = '#';
	for (int d = 0; d < 4; ++d)
		ans += dfs(l + dl[d], c + dc[d]);
	return ans;
}

int main()
{
	int T; scanf("%d\n", &T);
	for (int c = 1; c <= T; ++c) {
		scanf("%d\n", &N);
		for (int i = 0; i < N; ++i)
			scanf("%s\n", grid[i]);
		int ans = 0;
		for (int l = 0; l < N; ++l)
			for (int c = 0; c < N; ++c) if (grid[l][c] != '.') {
				if(dfs(l, c)) ans++;
			}
		printf("Case %d: %d\n", c, ans);
	}
}
