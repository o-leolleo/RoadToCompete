#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll l, r, k; bool f = true;
	scanf("%lld %lld %lld\n", &l, &r, &k);

	for (ll e = 1, old = e; (old == 1 || e / old == k) && e <= r; old = e, e *= k)
		if (e >= l) printf("%lld ", e), f = false;

	if (f) printf("-1");
	printf("\n");
}
