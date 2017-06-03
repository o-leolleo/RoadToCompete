#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, lim, m = 999999999, a, b;
	a = b = -1;

	scanf("%d\n", &n);

	for (int i = 1; i <= n; ++i)
		if (n%i==0 && abs(i - n/i) < m) {
			m = abs(i - n/i);
			a = min(i, n/i);
			b = max(i, n/i);
		}

	printf("%d %d\n", a, b);
}
