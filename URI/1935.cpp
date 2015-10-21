#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned ll;
ll N, B;

ll Sn(ll n) {
	return (4 * N - 4 * n) * n;
}

int main()
{
	scanf("%lld %lld\n", &N, &B);
	ll lo = 1, hi = N, mid;

	while (lo != hi) {
		mid = (lo + hi) / 2;
		if (Sn(mid) >= B)
			hi = mid;
		else
			lo = mid + 1;
	}
	// printf("%lld %lld %lld %lld<\n", hi, Sn(hi), mid, Sn(mid));
	ll l = N-2*(hi-1)-1, s0 = Sn(hi)-4*N+8*hi-3, c = 0;

	while (c < 4 && s0 < B) {
		s0 += l; c++;
	}

	if (s0 >= B && !(N == 3 && B == 9)) {
		ll delta = s0 - B;
		if (c == 1)
			printf("%lld %lld\n", hi, hi + l - delta);
		else if (c == 2)
			printf("%lld %lld\n", hi + l - delta, hi + l);
		else if (c == 3)
			printf("%lld %lld\n", hi + l, hi + delta);
		else
			printf("%lld %lld\n", hi + delta, hi);
	} else
		printf("%lld %lld\n", (N + 1) / 2, (N + 1) / 2);
}
