#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;

	scanf("%d\n", &n);

	printf("%d\n", n/2);
	while (n > 3) {
		n -= 2;
		printf("2 ");
	}

	if (n == 2) printf("2\n");
	else printf("3\n");
}
