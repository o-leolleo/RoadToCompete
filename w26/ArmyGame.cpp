#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	scanf("%d %d\n", &n, &m);
	printf("%d\n", (n/2)*(m/2) + (n/2)*(m%2) + (m/2)*(n%2) + (m%2)*(n%2));
	return 0;
}

