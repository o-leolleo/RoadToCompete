#include <cstdio>

int main()
{
        int N, tmp, i;

        while (scanf("%d\n", &N) && N) {
                i = 0;
                while (i++ < N && scanf("%d\n", &tmp) && !tmp);

                if (i == N)
                        printf("0\n");
                else {
                        printf("%d", tmp);
                        for (int j = i; j < N; ++j) {
                                scanf("%d\n", &tmp); if(tmp) printf(" %d", tmp);
                        }
                        printf("\n");
                }
        }
}
