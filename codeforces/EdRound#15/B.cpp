#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	map<int, int> freq;

	scanf("%d\n", &n);

	for (int i = 0; i < n; ++i) {
		int tmp;
		scanf("%d\n", &tmp);

		if (!freq.count(tmp))
			freq[tmp] = 1;
		else
			freq[tmp]++;
	}

	ll pot = 0;
	map<int, int>::iterator i;

	for (i = freq.begin(); i != freq.end(); ++i) {
		for (ll k = 1; k < 2000000000l; k <<= 1) {
			if (k - i->first < i->first) pot += i->second * freq[k - i->first];
			else if (k - i->first == i->first) pot += (ll)(i->second) * (i->second - 1) / 2;
		}
	}

	printf("%lld\n", pot);
}
