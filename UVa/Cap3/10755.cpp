#include <cstdio>
#include <climits>
#include <cstring>
#define max(a, b) (a > b ? a : b)
long long garbage[25][25][25];

int main()
{
        int T; scanf("%d\n", &T);

        while (T--) {
                int A, B, C; scanf("%d %d %d\n", &A, &B, &C);
                int ans = INT_MIN, sum = 0;

                for (int i = 0; i < A; ++i)
                        for (int j = 0; j < B; ++j)
                                for (int k = 0; k < C; ++k) {
                                        scanf("%lld\n", &garbage[i][j][k]);

                                        if (j > 0) garbage[i][j][k] += garbage[i][j - 1][k];
                                        if (k > 0) garbage[i][j][k] += garbage[i][j][k - 1];
                                        if (k > 0 && j > 0) garbage[i][j][k] -= garbage[i][j - 1][k - 1];
                                }

                long long g_ans = INT_MIN;

                for (int y1 = 0; y1 < B; ++y1)
                        for (int z1 = 0; z1 < C; ++z1)
                                for (int y2 = y1; y2 < B; ++y2)
                                        for (int z2 = z1; z2 < C; ++z2) {
                                                long long sum = 0, ans = INT_MIN;

                                                for (int x = 0; x < A; ++x) {
                                                        sum += garbage[x][y2][z2];

                                                        if (y1 > 0) sum -= garbage[x][y1 - 1][z2];
                                                        if (z1 > 0) sum -= garbage[x][y2][z1 - 1];
                                                        if (y1 > 0 && z1 > 0) sum += garbage[x][y1 - 1][z1 - 1];

                                                        ans = max(ans, sum);

                                                        if (sum < 0) sum = 0;
                                                }

                                                g_ans = max(g_ans, ans);
                                        }
                printf("%lld\n", g_ans);
                if(T) printf("\n");
        }
}
