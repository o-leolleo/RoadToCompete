#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> toy, choos;

ll prefix(ll a) {
	if (a < 0) return 0;
	return a * (a+1)/2;
}

ll search(ll l, ll h, ll m)
{
	ll ans, mid, low = l - 1;
	ans = -1;

	while (h >= l) {
		mid = (h + l) / 2;

		if (prefix(mid) - prefix(low) > m) {
			h = mid - 1;
		} else {
			l = mid + 1;
			ans = mid;
		}
	}

	return ans;
}

int main()
{
	ll n, m, sum = 0;

	scanf("%lld %lld\n", &n, &m);

	toy.push_back(0);

	for (int i = 0; i < n; ++i) {
		ll tmp; scanf("%lld\n", &tmp);
		toy.push_back(tmp);
	}

	sort(toy.begin(), toy.end());

	for (int i = 0; i < n; ++i) {
		if (toy[i+1] - toy[i] > 1) {
			ll k = search(toy[i] + 1, toy[i + 1] - 1, m);

			if (k > 0) {
				sum += prefix(k) - prefix(toy[i]);
				m -= (prefix(k) - prefix(toy[i]));

				for (int c = toy[i] + 1; c <= k; ++c)
					choos.push_back(c);
			} else 
				break;
		}	
	}

	if (m - toy[n] > 0) {
		ll k = search(toy[n] + 1, 1000000000ll, m);

		if (k > 0)
			for (int i = toy[n] + 1; i <= k; ++i)
				choos.push_back(i);
	}

	printf("%lld\n", (ll) choos.size());

	for (int k = 0; k < choos.size(); ++k)
		printf("%lld%c", choos[k], k + 1 == choos.size() ? '\n' : ' ');
}
