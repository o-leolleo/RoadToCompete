#include <cstdio>
#define MAX 110
char field[MAX];

int main()
{
        int T, N, count;

        scanf("%d\n", &T);

        for (int caso = 1; caso <= T; ++caso) {
                scanf("%d\n", &N);
                scanf("%s\n", field);

                count = 0;

                for (int i = 0; i < N;)
                        if (field[i] == '#')
                                i++;
                        else {
                                count++;
                                i += 3;
                        }

                printf("Case %d: %d\n", caso, count);
        }
}
