#include <bits/stdc++.h>
using namespace std;

int main()
{
	int b;
	long long P = (long long) pow(2, 31) - 1, ans = 1, a = 3;
	scanf("%d\n", &b);
	while (1) {
		if (b % 2 == 1)
			ans = (ans * a) % P;
		b >>= 2;
		if (b == 0) break;
		a = (a * a) % P;
	}

	printf("%lld\n", ans);
}
