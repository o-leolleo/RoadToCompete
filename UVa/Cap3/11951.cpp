#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
long long Area[101][101];

int main()
{
        int T, N, M, K;

        scanf("%d\n", &T);

        for (int caso = 1; caso <= T; caso++) {
                scanf("%d %d %d\n", &N, &M, &K);

                for (int i = 0; i < N; ++i)
                        for (int j = 0; j < M; ++j) {
                                scanf("%lld\n", &Area[i][j]);

                                if (i > 0) Area[i][j] += Area[i - 1][j];
                                if (j > 0) Area[i][j] += Area[i][j - 1];
                                if (i > 0 && j > 0) Area[i][j] -= Area[i - 1][j - 1];
                        }

                long long  Ma = 0, min_cost = 0, area, sum;

                for (int a = 0; a < N; ++a)
                        for (int b = 0; b < M; ++b)
                                for (int c = a; c < N; ++c)
                                        for (int d = b; d < M; ++d) {
                                                sum = Area[c][d];

                                                if (a > 0) sum -= Area[a - 1][d];
                                                if (b > 0) sum -= Area[c][b - 1];
                                                if (a > 0 && b > 0) sum += Area[a - 1][b - 1];

                                                area = (c - a + 1) * (d - b + 1);

                                                if (area >= Ma && sum <= K) {
                                                        if (area == Ma)
                                                                min_cost = min(min_cost, sum);
                                                        else
                                                                min_cost = sum;

                                                        Ma = area;
                                                }
                                        }

                printf("Case #%d: %lld %lld\n", caso, Ma, min_cost);
        }
}
