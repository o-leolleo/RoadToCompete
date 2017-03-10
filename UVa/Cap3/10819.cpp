#include <bits/stdc++.h>
using namespace std;
#define MAX_N 110
#define MAX_M 10210
int V[MAX_N], W[MAX_N], dp[2][MAX_N][MAX_M], N, M;

int ks(int id, int remW, int choos)
{
        if (!remW || id == N) {
                if (choos && M + 200 - remW <= 2000) return -100000;
                return 0;
        }

        if (dp[choos][id][remW] != -1) return dp[choos][id][remW];
        if (W[id] > remW) return dp[choos][id][remW] = ks(id + 1, remW, choos);
        return dp[choos][id][remW] = max(ks(id + 1, remW, choos), V[id] + ks(id + 1, remW - W[id], choos));
}

int main()
{
        while (scanf("%d %d\n", &M, &N) != EOF) {
                for (int id = 0; id < N; ++id)
                        scanf("%d %d\n", &W[id], &V[id]);

                memset(dp, -1, sizeof dp);
                printf("%d\n", max(ks(0, M, 0), ks(0, M + 200, 1)));
        }
}
