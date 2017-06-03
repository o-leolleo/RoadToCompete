#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define MAX 200100
#define F first
#define S second
ii chs[MAX], prg[MAX];

int dist(ii a, ii b)
{
    if (a.S < b.F) return b.F - a.S;
    if (a.F > b.S) return a.F - b.S;
    return 0;
}

bool comp_st(ii a, ii b)
{
    if (a.S < b.S) return true;
    if (a.S == b.S) return a.F < b.F;
    return false;
}

int main()
{
    int n, m;

    scanf("%d\n", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d %d\n", &chs[i].F, &chs[i].S);

    scanf("%d\n", &m);

    for (int i = 0; i < m; ++i)
        scanf("%d %d\n", &prg[i].F, &prg[i].S);

    sort(chs, chs + n, comp_st);
    sort(prg, prg + m);

    int d1 = dist(chs[0], prg[m-1]);

    sort(prg, prg + m, comp_st);
    sort(chs, chs + n);

    int d2 = dist(chs[n-1], prg[0]);

    printf("%d\n", max(d1, d2));
}
