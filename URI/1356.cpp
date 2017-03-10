#include <bits/stdc++.h>
using namespace std;
#define LSOne(x) (x & (-x))
typedef long long ll;
typedef vector<ll> vll;
ll P, B;

ll mod_pow(int k)
{
	ll r = 1, a = B;
	while(1) {
		if (k % 2 == 1) r = r * a % P;
		k /= 2;
		if (k == 0) break;
		a = a * a % P;

	}
	return r;
}

ll mod (ll a) {
	ll ret = a % P;
   	if(ret < 0)
     		ret += P;
	return ret;
}

class FenwickTree
{
private: vll ft;
public:
	void init(int N) {
		ft.assign(N + 1, 0);
	}

	ll rsq(int b) {
		ll old = 0, sum = 0;
		for (; b; old += LSOne(b), b -= LSOne(b))
			sum = (sum + mod_pow(old) * (ft[b] % P) % P) % P;
		return sum;
	}

	ll rsq(int a, int b) {
		return mod(rsq(b) % P - (a == 1 ? 0 : mod_pow(b - a + 1) * (rsq(a - 1) % P) % P));
	}

	void adjust(int k, int v) { int memo = k;
		for(; k < (int) ft.size(); k += LSOne(k)) ft[k] = (ft[k] + mod_pow(k - memo) * (v % P) % P) % P;
	}
};
int main()
{
	ll L, N; FenwickTree hard;

	while (scanf("%lld %lld %lld %lld\n", &B, &P, &L, &N) && B) {
		hard.init(L);
		ll A[L + 10]; memset(A, 0, sizeof A);

		while (N--) {
			char type; ll I, J;
			scanf("%c %lld %lld\n", &type, &I, &J);

			if (type == 'H') {
				printf("%lld\n", hard.rsq(I, J));
			} else {
				hard.adjust(I, -A[I]);
				A[I] = J;
				hard.adjust(I, J);
			}
		}
		printf("-\n");
	}
}
