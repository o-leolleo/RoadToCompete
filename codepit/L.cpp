#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T, n;
	scanf("%d\n", &T);

	for (int c = 1; c <= T; ++c) {
		scanf("%d\n", &n);
		printf("Case #%d: %d\n", c, 2 * n - 1);
	}
}
