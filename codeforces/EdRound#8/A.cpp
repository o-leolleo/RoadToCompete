#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, p, q, m, bot;
	scanf("%d %d %d\n", &n, &p, &q);
	bot = 0;
	m = n;
	int k;
	
	if (n == 1) {
		printf("%d %d\n", bot, q);
		exit(0);
	}

	do {
		int t = 0;
		while (k <= m) { k = 1 << t; t++; }
		k/=2;
		bot += p * k + k/2;
	} while ((m -= (k - k/2)) > 1);

	printf("%d %d\n", bot, q * n);
}
