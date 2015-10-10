#include <cstdio>
#include <climits>
#define max(a, b) (a > b ? a : b)
int A[110][110];
int main()
{
        int N;
        scanf("%d\n", &N);

        for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j) {
                        scanf("%d\n", &A[i][j]);
                        if (i > 0) A[i][j] += A[i-1][j];
                        if (j > 0) A[i][j] += A[i][j-1];
                        if (i > 0 && j > 0) A[i][j] -= A[i-1][j-1];
                }

        int ans = INT_MIN;

        for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                        for (int n = i; n < N; ++n)
                                for (int m = j; m < N; ++m) {
                                        int sum = A[n][m];

                                        if (i > 0) sum -= A[i-1][m];
                                        if (j > 0) sum -= A[n][j-1];
                                        if (i > 0 && j > 0) sum += A[i-1][j-1];

                                        ans = max(ans, sum);
                                }

        printf("%d\n", ans);
}
