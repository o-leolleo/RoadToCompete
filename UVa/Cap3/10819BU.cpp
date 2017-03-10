#include <bits/stdc++.h>
using namespace std;
#define MAX_N 110
#define MAX_M 10210
int V[MAX_N], W[MAX_N] dp[MAX_N][MAX_M], N, M;

int main()
{
	while (scanf("%d %d\n", &M, &N) != EOF) {
		for (int i = 1; i <= N; ++i)
			scanf("%d %d\n", &W[i], &V[i]);

		for (int i = 0; i <= N; ++i) dp[i][0] = 0;
		for (int w = 1; w <= M; ++i) dp[0][w] = 0;

		for (int id = 1; id <= N; ++id) {
			for (int w = 1; w <= M; ++w) {
				if (W[id] > w) dp[id][w] = dp[id - 1][w];
				else dp[id][w] = max(dp[id - 1][w], V[id] + dp[id - 1][w - W[id]]);
			}
		}
	}
}
