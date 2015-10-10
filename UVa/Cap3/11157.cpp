#include <cstdio>
#define MAX 110
int rock[MAX];
char type[MAX];

int main()
{
        int N, T, D;

        scanf("%d\n", &T);

        for (int caso = 1; caso <= T; ++caso) {
                scanf("%d %d\n", &N, &D);

                for (int i = 1; i <= N; ++i)
                        scanf("%c-%d\n", &type[i], &rock[i]);

                type[0] = type[N + 1] = 'B';
                rock[0] = 0;
                rock[N + 1] = D;

                int Max = -1, old, next;

                old = next = 0;

                while (next <= N) {
                        if (type[old] == 'S' && type[old + 1] == 'S')
                                next += 2;
                        else
                                next++;

                        if (rock[next] - rock[old] > Max)
                                Max = rock[next] - rock[old];

                        if (type[old] == 'S')
                                rock[old] = -1;

                        old = next;
                }

                old = next = 0;

                while (next <= N) {
                        if (rock[old + 1] < 0)
                                next += 2;
                        else
                                next++;

                        if (rock[next] - rock[old] > Max)
                                Max = rock[next] - rock[old];

                        old = next;
                }

                printf("Case %d: %d\n", caso, Max);
        }
}
