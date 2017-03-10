#include <bits/stdc++.h>
using namespace std;
int coord[11][2], dp[11][6000], dist[25][25], N;

int tsp(int pos, int bitmask)
{
	if (bitmask == (1 << (N + 1)) - 1) return dist[pos][0];
	if (dp[pos][bitmask] != -1) return dp[pos][bitmask];
	int &ans = dp[pos][bitmask];
	ans = 9999999;
	for (int nxt = 0; nxt <= N; ++nxt)
		if (nxt != pos && !(bitmask & (1 << nxt)))
			ans = min(ans, dist[pos][nxt] + tsp(nxt, bitmask | (1 << nxt)));
	return ans;
}

int main()
{
	int sc; scanf("%d\n", &sc);

	while (sc--) {
		int X, Y;
		scanf("%d %d %d %d %d\n", &X, &Y, &coord[0][0], &coord[0][1], &N);

		for (int i = 1; i <= N; ++i)
			scanf("%d %d\n", &coord[i][0], &coord[i][1]);

		memset(dp, -1, sizeof dp);

		for (int a = 0; a <= N; ++a)
			for (int b = a + 1; b <= N; ++b)
				dist[a][b] = dist[b][a] = abs(coord[a][0] - coord[b][0]) + abs(coord[a][1] - coord[b][1]);

		printf("The shortest path has length %d\n", tsp(0,1));
	}
}
