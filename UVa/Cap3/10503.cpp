#include <cstdio>
#define MAX 17

int dom[MAX][2], a[MAX], us;
bool finished;

void backtrack(int k, int n, int p, int beg)
{
        if(k > p) {
                if(dom[a[k - 1]][1] == dom[a[k]][0]) {
                        printf("YES\n");
                        finished = true;
                }
        } else {
                for (int i = beg; i <= n && !finished; ++i) {
                        if (!(us & (1 << i))) {
                                bool c = false;

                                if (dom[i][1] == dom[a[k - 1]][1]) {
                                        int tmp = dom[i][1];
                                        dom[i][1] = dom[i][0];
                                        dom[i][0] = tmp;
                                        c = true;
                                }

                                if (dom[i][0] == dom[a[k - 1]][1]) {
                                        us  |= (1 << i);
                                        a[k] = i;
                                        backtrack(k + 1, n, p, beg);
                                        us  &= ~(1 << i);

                                        if(c) {
                                                int tmp = dom[i][1];
                                                dom[i][1] = dom[i][0];
                                                dom[i][0] = tmp;
                                        }
                                }
                        }
                }
        }
}

int main()
{
        int n, m;

        while (scanf("%d\n", &n) && n) {
                scanf("%d\n", &m);
                scanf("%d %d\n", &dom[0][0], &dom[0][1]);
                scanf("%d %d\n", &dom[m + 1][0], &dom[m + 1][1]);

                for (int i = 1; i < m + 1; ++i)
                        scanf("%d %d\n", &dom[i][0], &dom[i][1]);

                a[0] = 0;
                a[n + 1] = m + 1;
                us = 0;
                finished = false;
                backtrack(1, m, n, 1);

                if(!finished)
                        printf("NO\n");
        }
}
