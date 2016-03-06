#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, sum = 0;
	scanf("%d\n", &x);

	if (x >= 5) sum += x/5, x -= x/5 * 5;
	if (x >= 4) sum += x/4, x -= x/4 * 4;
	if (x >= 3) sum += x/3, x -= x/3 * 3;
	if (x >= 2) sum += x/2, x -= x/2 * 2;
	if (x >= 1) sum += x;

	printf("%d\n", sum);
}
