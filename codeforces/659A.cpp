#include <bits/stdc++.h>

int main()
{
	int n, a, b, res;

	scanf("%d %d %d\n", &n, &a, &b);
	a--;
	res = (a + b) % n;

	if(res < 0) res+=n;

	printf("%d\n", res + 1);
}
