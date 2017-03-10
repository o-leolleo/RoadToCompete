#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c;

ll alfa(ll n)
{
	ll hi = n, lo = 0, mid, ans = 0;

	while (lo <= hi) {
		mid = (hi + lo) / 2;

		if (n/a - mid < 1) {
			hi = mid - 1;
			ans = mid;
		} else
			lo = mid + 1;
	}

	return ans;
}

ll beta(ll n)
{
	ll hi = n, lo = 0, mid, ans = 0;

	while (lo <= hi) {
		mid = (hi + lo) / 2;

		if (n/(b-c) - mid - b / (b - c) < 0) {
			hi = mid - 1;
			ans = mid;
		} else
			lo = mid + 1;
	}

	return ans;
}

int main()
{
	ll n;
	scanf("%lld %lld %lld %lld\n", &n, &a, &b, &c); 

	if (b - c <= a) {
		ll x = beta(n);
		n -= x * (b - c);
		printf("%lld\n", x + alfa(n));
	} else {
		ll x = alfa(n);
		n -= x * a;
		printf("%lld\n", x + beta(n));
	}
}
