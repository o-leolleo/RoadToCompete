#include <cstdio>
#define VES 1000

int vessels[VES], n, m;

bool can(int size)
{
        int sum = 0, cont = 0, f;

        for (int i = 0; i < n; ++i) {
                sum += vessels[i];

                if (vessels[i] > size) return false;
                if (sum > size) {
                        sum = vessels[i];
                        cont++;
                }
        }

        cont++;

        return cont <= m;
}

int main()
{
        while (scanf("%d %d\n", &n, &m) != EOF) {
                int sum = 0;

                for (int i = 0; i < n; ++i) {
                        scanf("%d\n", &vessels[i]);
                        sum += vessels[i];
                }


                int hi, lo, mid, save;

                hi = sum + 10;
                lo = 0;

                while ((hi - lo) > 0) {
                        mid = (lo + hi) / 2;

                        if (can(mid)) {
                                hi = mid;
                                save = mid;
                        } else
                                lo = mid + 1;
                }

                printf("%d\n", save);
        }
}
