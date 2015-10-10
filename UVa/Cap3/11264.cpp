#include <cstdio>
#include <cstdlib>
#define MAX 1010
int coins[MAX], N;

int main()
{
        int T;

        scanf("%d\n", &T);

        while (T--) {
                scanf("%d\n", &N);

                for (int i = 0; i < N; ++i)
                        scanf("%d\n", &coins[i]);

                int S = 1, ans = 1;

                for (int i = 1; i < N - 1; ++i)
                        if (S + coins[i] < coins[i + 1]) {
                                S += coins[i];
                                ans++;
                        }

                printf("%d\n", ans + 1);
        }
}
