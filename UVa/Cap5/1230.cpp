#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll modPow(ll a, ll b, ll p) {
	ll r = 1;
	while(b) {
		if (b % 2 == 1)
			r = r * a % p;
		a = a * a % p;
		b /= 2;
	}
	return r;
}
int main()
{
	int x, n, y, c;
	scanf("%d\n", &c);
	while(c--) {
		scanf("%d %d %d\n", &x, &y, &n);
		printf("%lld\n", modPow(x,y,n));
	}
}
