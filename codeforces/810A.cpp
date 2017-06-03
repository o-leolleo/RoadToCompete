#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, x[200], Sn;
    scanf("%d %d\n", &n, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%d\n", &x[i]);
        Sn += x[i];
    }

    printf("%d\n", max(max((int)ceil(2*(n*k-Sn)-n), (int)ceil(2*(Sn-n*k)-n)), 0));
}
