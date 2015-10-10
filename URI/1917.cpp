#include <cstdio>
#define MAX 1000000
long long sum[MAX], created[MAX];

int main()
{
        long long X, Mf;

        while (scanf("%lld %lld\n", &X, &Mf) && (X)) {
                sum[0] = X; created[0] = X;

                for (int i = 1; i <= Mf; ++i) {
                        sum[i] = 2 * sum[i - 1] - (i - 2 >= 0 ? created[i - 2] : 0);
                        created[i] = sum[i - 1];
                }

                printf("%lld\n", sum[Mf]);
        }
}
