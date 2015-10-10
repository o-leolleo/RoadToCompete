#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 500

int grid[MAX][MAX];

int main()
{
        int N, M, L, U, Q;

        while (scanf("%d %d\n", &N, &M) && (N || M)) {
                for (int i = 0; i < N; ++i)
                        for (int j = 0; j < M; ++j)
                                scanf("%d\n", &grid[i][j]);

                scanf("%d\n", &Q);

                while (Q--) {
                        scanf("%d %d\n", &L, &U);

                        int *down, *up, t1, t2, dim_ctrl = 0, column, ol, ou, B = -1;
                        bool f = false;

                        for (int i = 0; i < N; ++i) {
                                down = lower_bound(grid[i], grid[i] + M, L);

                                if (down != grid[i] + M && *down <= U) {
                                        up = upper_bound(down, grid[i] + M, U);
                                        t1 = down - grid[i];
                                        t2 = up - grid[i] - 1;
                                        //
                                        // if(f)
                                        //         printf("%d %d %d %d\n", t1, t2, ol, ou);

                                        if (!f) {
                                                ol = t1;
                                                ou = t2;
                                                f  = true;
                                        }

                                        if (t2 < ol || dim_ctrl >= ou - ol + 1)
                                                dim_ctrl = 0;
                                        else {
                                                t1 = max(t1, ol);
                                                t2 = min(t2, ou);
                                        }

                                        dim_ctrl++;

                                        ol = t1;
                                        ou = t2;
                                }
                        }

                        int tmp = min(dim_ctrl, ou - ol + 1);
                        if(tmp > B) B = tmp;


                        printf("%d\n", B);
                }

                printf("-\n");
        }
}
