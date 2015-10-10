#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 10010
long long ev[MAX], mor[MAX];

int main()
{
        long long d;
        int n, r;

        while (scanf("%d %d %d\n", &n, &d, &r) && n) {
                for (int i = 0; i < n; ++i) scanf("%d\n", &mor[i]);
                for (int i = 0; i < n; ++i) scanf("%d\n", &ev[i]);

                sort(mor, mor + n); sort(ev, ev + n);

                long long sum = 0;

                for (int i = 0; i < n; ++i) {
                        if (mor[i] + ev[n - 1 - i] > d)
                                sum += (mor[i] + ev[n - 1 - i] - d) * r;
                }

                printf("%d\n", sum);
        }
}
