#include <cstdio>
#include <vector>

using namespace std;

vector<int> common[10];
int towers[21], v[21], M, max_v[21];

void process(int n)
{
    int sum = 0, card;

    for(int i = 0; i < n; ++i)
        sum += towers[ v[i] ];

    for(int j = 0; !common[j].empty(); ++j) {
        int count = 0;

        for(int k = 0; k < common[j].size() - 1; ++k)
            for(int p = 0; p < n; ++p)
                if(v[p] == common[j][k])
                    count++;

        if(count) sum -= (count - 1) * common[j][ common[j].size() - 1 ];
    }

    if(sum > M) {
        M = sum;

        for(int i = 0; i < n; ++i)
            max_v[i] = v[i];
    }
}

void comb(int n, int p, int b, int l)
{
    if(p == 0)
        process(l);
    else
        for(int i = b; i <= n - p + 1; ++i) {
            v[l] = i;
            comb(n, p - 1, i + 1, l + 1);
        }
}

int main()
{
    int n, t, m, tmp, b, Case = 0;

    while( scanf("%d %d\n", &n, &b) && (n || b) ) {
        for(int i = 1; i <= n; ++i)
            scanf("%d\n", &towers[i]);

        scanf("%d\n", &m);

        for(int i = 0; i < m; ++i) {
            scanf("%d\n", &t);

            while(t--) {
                scanf("%d\n", &tmp);
                common[i].push_back(tmp);
            }

            scanf("%d\n", &tmp);
            common[i].push_back(tmp);
        }

        M = -1;

        comb(n, b, 1, 0);
        printf("Case Number  %d\nNumber of Customers: %d\nLocations recommended:", ++Case, M);

        for(int i = 0; i < b; ++i)
            printf(" %d", max_v[i]);
        printf("\n\n");

        for(int i = 0; i < m; ++i)
            common[i].clear();
    }
}
