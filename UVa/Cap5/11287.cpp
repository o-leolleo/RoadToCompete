#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isPrime (int n) {
	int lim = (int)sqrt(n);
	if (n % 2 == 0) return false;
	for (int i = 3; i <= lim; i += 2)
		if (n % i == 0) return false;
	return true;
}

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
	int a, p;

	while (scanf("%d %d\n", &p, &a) && a) {
		if (!isPrime(p) && modPow(a,p,p) == a)
			printf("yes\n");
		else
			printf("no\n");
	}
}
