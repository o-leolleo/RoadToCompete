#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, young, old, len = 1, max_len = -1;

	scanf("%d\n", &n);
	scanf("%d\n", &young);

	for(int i = 1; i < n; ++i) {
		old = young;
		scanf("%d\n", &young);

		if (young - old > 0) {
			len++;
		} else { 
			max_len = max(len, max_len);
			len = 1;
		}
	}

	max_len = max(len, max_len);
	printf("%d\n", max_len);

}
