#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 20020
int dragon[MAX], knight[MAX];

int main()
{
        int n, m;

        while (scanf("%d %d\n", &n, &m) && (n || m)) {
                for (int i = 0; i < n; ++i) scanf("%d\n", &dragon[i]);
                for (int i = 0; i < m; ++i) scanf("%d\n", &knight[i]);
                sort(dragon, dragon + n);
                sort(knight, knight + m);

                int d, k, money; k = money = 0; d = -1;

                while (++d < n) {
                        while (k < m && knight[k] < dragon[d]) k++;
                        if (k == m) break;
                        money += knight[k++];
                }

                if (d < n) printf("Loowater is doomed!\n");
                else printf("%d\n", money);
        }
}
