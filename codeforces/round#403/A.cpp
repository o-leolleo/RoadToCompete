#include <bits/stdc++.h>
using namespace std;

int main()
{
	bool pair[100100];
	int sock[300000];
	int n;

	scanf("%d\n", &n);

	for (int i = 0; i < 2 * n; i++) 
		scanf("%d\n", &sock[i]);

	memset(pair, false, sizeof pair);
	
	int sum = 0, M = -1;

	for (int i = 0; i < 2 * n; ++i) {
		if (!pair[sock[i]]) {
			sum++;
			pair[sock[i]] = true;
		} else {
			sum--;
			pair[sock[i]] = false;
		}

		M = max(sum, M);	
	}

	printf("%d\n", M);
}
