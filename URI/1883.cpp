#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 1010
char grid[MAX][MAX];
int d[MAX * MAX],
dr[] = {1, 0, 0, -1},
dc[] = {0, 1, -1, 0};
queue<int> q;

int main()
{
        int T, N, M; scanf("%d\n", &T);

        while (T--) {
                scanf("%d %d\n", &N, &M);

                int beg, end;

                for (int i = 0; i < N; ++i)
                        for (int j = 0; j < M; ++j) {
                                scanf("%c\n", &grid[i][j]);

                                if (grid[i][j] == 'S')
                                        beg = i * M + j;
                                else if (grid[i][j] == 'E')
                                        end = i * M + j;
                        }

                memset(d, -1, sizeof d);
                q.push(end);
                d[end] = 0;

                bool opa = false;
                int menor = -1;

                while (!q.empty()) {
                        int u = q.front(); q.pop();

                        for (int i = 0; i < 4; ++i) {
                                int adj = u + dr[i] * M + dc[i], line = u / M, col = u % M;

                                if ((line + dr[i] >= 0 && col + dc[i] >= 0 && line + dr[i] < N && col + dc[i] < M) &&
                                        (d[adj] < 0) &&
                                        (grid[adj / M][adj % M] != '#')
                                ) {
                                        d[adj] = d[u] + 1;

                                        if (!opa && (grid[adj / M][adj % M] == 'F')) {
                                                menor = adj; opa = true;
                                        }

                                        q.push(adj);
                                }
                        }
                }

                if (menor < 0 || (d[beg] > 0 && d[beg] < d[menor]))
                        printf("Y\n");
                else
                        printf("N\n");
        }
}
