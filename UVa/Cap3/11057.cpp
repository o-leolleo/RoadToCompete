#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define MAX 10001

int bp[MAX];

int main()
{
        int N, M;

        while (scanf("%d\n", &N) != EOF) {
                for (int i = 0; i < N; ++i)
                        scanf("%d\n", &bp[i]);

                scanf("%d\n", &M);

                sort(bp, bp + N);

                int l = 9999999, b1, b2,
                    j = lower_bound(bp, bp + N, M/2) - bp;

                for (; j < N; ++j)
                        if (binary_search(bp, bp + j, M - bp[j]) && (2 * bp[j] - M < l)) {
                                l  = 2 * bp[j] - M;
                                b1 = M - bp[j];
                                b2 = bp[j];
                        }

                printf("Peter should buy books whose prices are %d and %d.\n\n", b1, b2);
        }
}
