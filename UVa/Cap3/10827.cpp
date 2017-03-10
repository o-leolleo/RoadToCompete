#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;
int torus[100][200];

int main()
{
        int T, N; scanf("%d\n", &T);

        while (T--) {
                scanf("%d\n", &N);

                for (int i = 0; i < N; ++i)
                        for (int j = 0; j < N; ++j) {
                                scanf("%d\n", &torus[i][j]);
                                if (j < N - 1) torus[i][j + N] = torus[i][j];

                                if (i > 0) torus[i][j] += torus[i - 1][j];
                                if (j > 0) torus[i][j] += torus[i][j - 1];
                                if (i > 0 && j > 0) torus[i][j] -= torus[i - 1][j - 1];
                        }

                for (int i = 0; i < N; ++i)
                        for (int j = N; j < 2 * N - 1; ++j) {
                                if (i > 0) torus[i][j] += torus[i - 1][j];
                                if (j > 0) torus[i][j] += torus[i][j - 1];
                                if (i > 0 && j > 0) torus[i][j] -= torus[i - 1][j - 1];
                        }

                int ans = INT_MIN;

                for (int i = 0; i < N; ++i)
                        for (int j = 0; j < N; ++j)
                                for (int n = i; (n % N != i) || (n < N); ++n)
                                        for (int m = j; m < N + j; ++m) {
                                                int sum, x;

                                                x = n < N ? n : N - 1;
                                                sum = torus[x][m];

                                                if (i > 0) sum -= torus[i-1][m];
                                                if (j > 0) sum -= torus[x][j-1];
                                                if (i > 0 && j > 0) sum += torus[i-1][j-1];

                                                if (n >= N) {
                                                        sum += torus[n % N][m];
                                                        if (j > 0) sum -= torus[n % N][j-1];
                                                }

                                                ans = max(ans, sum);
                                        }

                printf("%d\n", ans);
        }
}
