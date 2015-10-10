#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_N 210
#define MAX_D 210
#define MAX_M 210
ll V[MAX_N], dp[MAX_N][MAX_D][MAX_M];
int M, N, Q, D;

ll gs(int id, int S, int k)
{
	if (!S && !k) return 1;
	if (!k || id >= N) return 0;

	if (dp[id][S][k] >= 0) return dp[id][S][k];

	return dp[id][S][k] = gs(id + 1, S, k) + gs(id + 1, (S + V[id]) % D, k - 1);
}

int main()
{
	int set_ct = 0;

	while(scanf("%d %d\n", &N, &Q) && N) {
		for (int i = 0; i < N; ++i)
			scanf("%lld\n", &V[i]);

		printf("SET %d:\n", ++set_ct);

		for (int q = 1; q <= Q; ++q) {
			scanf("%d %d\n", &D, &M);
			memset(dp, -1, sizeof dp);
			printf("QUERY %d: %lld\n", q, gs(0, D, M));
		}
	}
}
