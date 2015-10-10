#include <cstdio>
#define max(a, b) (a > b ? a : b)
int main()
{
        int N;

        while (scanf("%d\n", &N) && N) {
                int sum = 0, ans = 0, tmp;

                for (int i = 0; i < N; ++i) {
                        scanf("%d\n", &tmp);

                        sum += tmp;
                        ans  = max(ans, sum);
                        if (sum < 0) sum = 0;
                }

                if (ans > 0)
                        printf("The maximum winning streak is %d.\n", ans);
                else
                        printf("Losing streak.\n");
        }
}
