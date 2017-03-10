#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 10010
int lugg[MAX];

int main()
{
        int N, k; bool sta = false;

        while (scanf("%d\n", &N) && N) {
                if (sta) printf("\n");

                for (int i = 0; i < N; ++i)
                        scanf("%d\n", &lugg[i]);

                sort(lugg, lugg + N);

                int f = 1; k = -1;

                for (int i = 1; i < N; ++i, ++f)
                        if (lugg[i - 1] != lugg[i]) {
                                if (f > k) k = f;
                                f = 0;
                        }

                if (f > k) k = f;

                printf("%d\n", k);

                for (int i = 0; i < k; ++i) {
                        int j = i;
                        printf("%d", lugg[i]);

                        while ((j += k) < N)
                                printf(" %d", lugg[j]);

                        printf("\n");
                }

                sta = true;
        }
}
