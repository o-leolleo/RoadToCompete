#include <bits/stdc++.h>
using namespace std;
#define LSOne(x) (x & (-x))
typedef long long ll;

class FT
{
private: vector<ll> ft;
public:
	void init(int N) {
		ft.assign(N + 1, 0);
	}

	ll rsq(int a) {
		ll sum = 0;
		for (; a; a -= LSOne(a)) sum += ft[a];
		return sum;
	}

	void increment(int k, ll v) {
		for(; k <= ft.size(); k += LSOne(k)) ft[k] += v;
	}
};

class FTrange
{
private: FT t1, t2; int N;
public:
	void init(int N) {
		t1.init(N); t2.init(N);
		this->N = N;
	}

	void update(int a, int b, int v) {
		t1.increment(a, v);
		if (b + 1 <= N) t1.increment(b + 1, -1 * v);

		t2.increment(a, (a - 1) * v);
		if (b + 1 <= N) t2.increment(b + 1, -1 * b * v);
	}

	ll rsq(int b) {
		return t1.rsq(b) * b - t2.rsq(b);
	}

	ll rsq(int a, int b) {
		return rsq(b) - (a - 1 == 0 ? 0 : rsq(a - 1));
	}
};

FTrange ft[12];

int main()
{
	int r, c, n;
	scanf("%d %d %d", &r, &c, &n);
	getchar();
	for (int l = 1; l <= r; l++) ft[l].init(c);

	while(n--) {
		char t;
		int x1, y1, x2, y2;

		scanf("%c %d %d %d %d", &t, &x1, &y1, &x2, &y2);
		getchar();
		if (t == 'a') {
			for (int i = x1; i <= x2; ++i) ft[i].update(y1, y2, 1);
		} else if (t == 'r') {
			for (int i = x1; i <= x2; ++i) ft[i].update(y1, y2, -1);
		} else {
			ll sum = 0;
			for (int i = x1; i <= x2; ++i)
				sum += ft[i].rsq(y1, y2);
			printf("%lld\n", sum);
		}
	}

	return 0;
}
