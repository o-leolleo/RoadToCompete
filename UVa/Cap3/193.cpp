#include <cstdio>
#include <vector>
using namespace std;
#define MAX 101

vector<int> graph[MAX];
bool a[MAX], memo[MAX];
int M;

void coloring(int k, int n)
{
        if (k > n) {
                int count = 0;

                for (int i = 1; i < k; ++i)
                        if (a[i])
                                count++;

                if(count > M) {
                        M = count;

                        for (int i = 1; i < k; ++i)
                                memo[i] = a[i];
                }

        } else {
                bool black = false;

                for (int i = 0; i < graph[k].size(); ++i)
                        if (a[ graph[k][i] ])
                                black = true;

                if(!black) {
                        a[k] = true;
                        coloring(k + 1, n);
                }

                a[k] = false;
                coloring(k + 1, n);
        }
}

int main()
{
        int m, n, k, a, b;

        scanf("%d\n", &m);

        while (m--) {
                scanf("%d %d\n", &n, &k);

                for (int i = 0; i < k; ++i) {
                        scanf("%d %d\n", &a, &b);

                        graph[a].push_back(b);
                        graph[b].push_back(a);
                }

                M = -1;

                coloring(1, n);

                printf("%d\n", M);

                bool sta = false;

                for (int i = 1; i <= n; ++i)
                        if(memo[i]) {
                                if(sta) printf(" ");
                                printf("%d", i);
                                sta = true;
                        }

                printf("\n");

                for(int i = 1; i <= n; ++i)
                        graph[i].clear();
        }
}
