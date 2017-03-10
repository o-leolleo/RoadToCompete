#include <cstdio>
#define MAX 100010
int rungs[MAX], n;

bool can(int k)
{
        int old = 0, i;

        for (i = 0; i < n; ++i) {
                if (rungs[i] - old == k)
                        k--;
                else if (rungs[i] - old > k)
                        break;
                old = rungs[i];
        }

        return i == n;
}

int main()
{
        int T, hi, lo;

        scanf("%d\n", &T);

        for (int i = 1; i <= T; ++i) {
                scanf("%d\n", &n);

                for (int j = 0; j < n; ++j)
                        scanf("%d\n", &rungs[j]);

                lo = 0;
                hi = rungs[n - 1] + 10;
                int ans, mid;

                while (hi - lo > 0) {
                        mid = (hi + lo) / 2;

                        if (can(mid)) {
                                hi = mid;
                                ans = mid;
                        } else
                                lo = mid + 1;
                }

                printf("Case %d: %d\n", i, ans);
        }
}
