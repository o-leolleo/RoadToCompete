#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, n;
int main()
{
	scanf("%lld %lld\n", &n, &x);

	int count = 0;

	while (n--) {
		int d; char t;
		scanf("%c %d\n", &t, &d);

		if (t == '+') {
			x += d;
		} else {
			if (d > x) count++;
			else x -= d;
		}
	}

	printf("%lld %d\n", x, count);
}
