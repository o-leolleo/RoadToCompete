#include <cstdio>
#include <algorithm>
using namespace std;

char g[2][6][6], a[6];

void backtrack(int k, int i, int order, int *count)
{
        if (k >= 5) {
                (*count)++;

                if (order == *count) {
                        a[k] = '\0';
                        printf("%s\n", a);
                }
        } else {
                char can[6];
                int choss, tam;
                choss = tam = 0;

                for (int j = 0; j < 6; ++j)
                        for (int p = 0; p < 6; ++p)
                                if (g[0][j][i] == g[1][p][i] && !(choss & (1 << (g[1][p][i] - '0')))) {
                                        can[tam++] = g[0][j][i];
                                        choss |= (1 << (g[0][j][i] - '0'));
                                }

                sort(can, can + tam);

                for (int j = 0; (j < tam) && (*count < order); ++j) {
                        a[k] = can[j];
                        backtrack(k + 1, i + 1, order, count);
                }
        }
}

int main()
{
        int T;

        scanf("%d\n", &T);

        while (T--) {
                int K, count;

                scanf("%d\n", &K);

                for (int j = 0; j < 2; ++j)
                        for (int i = 0; i < 6; ++i)
                                scanf("%s\n", g[j][i]);

                count = 0;
                backtrack(0, 0, K, &count);

                if (K > count) printf("NO\n");
        }
}
