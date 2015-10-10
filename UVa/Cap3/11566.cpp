#include <bits/stdc++.h>
using namespace std;
#define MAX_COST 1010
#define MAX_K 210
#define MAX_N 15
int W[MAX_K], V[MAX_K], dp[MAX_K][MAX_COST][2 * MAX_N];
int N, x, T, K;

int ks(int id, int remW, int tdish)
{
	if (!remW || remW < 0 ||id == K || tdish == 2 * N) return 0;
	int &ans = dp[id][remW][tdish];
	if (ans != -1) return ans;
	if (W[id] > remW) return ans = ks(id + 1, remW, tdish);
	return ans = max( ks(id + 1, remW, tdish), V[id] + ks(id + 1, remW - W[id], tdish + 1));
}

int main()
{
	while (scanf("%d %d %d %d\n", &N, &x, &T, &K) && N) {
		K *= 2; N++; x *= N;

		for (int i = 0; i < K; i += 2) {
			int sum = 0, f;
			scanf("%d\n", &W[i]);
			W[i + 1] = W[i];

			for (int j = 0; j < N; ++j) {
				scanf("%d\n", &f);
				sum += f;
			}

			V[i] = V[i + 1] = sum;
		}

		memset(dp, -1, sizeof dp);
		double ans = ks(0, floor((double)(x) / 1.1 + 1e-6) - N * T, 0);

		printf("%.2lf\n", ans / N);
	}
}
