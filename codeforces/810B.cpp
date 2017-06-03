#include <bits/stdc++.h>
using namespace std;
#define MAX 100100
#define F first
#define S second
typedef long long ll;
typedef pair<ll, ll> ii;

ii days[MAX];

bool comp(ii a, ii b) { 
    return min(2*a.F, a.S) - min(a.F, a.S) > min(2*b.F, b.S) - min(b.F, b.S);
}

int main()
{
    int n, f;
    ll ans = 0;

    scanf("%d %d\n", &n, &f);

    for (int i = 0; i < n; ++i) 
        scanf("%lld %lld\n", &days[i].F, &days[i].S);

    sort(days, days + n, comp);

    for (int k = 0; k < n; ++k) {
        if (f) {
            ans += min(2*days[k].F, days[k].S);
            f--;
        } else
            ans += min(days[k].F, days[k].S);
    }

    printf("%lld\n", ans);
}
