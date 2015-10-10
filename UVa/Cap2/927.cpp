#include <cstdio>
#include <cmath>

typedef unsigned long long ull;

int cj[23];

int main()
{
	int C, d, k, i;
	char buffer[23];

	scanf("%d\n", &C);

	while(C--) {
		scanf("%d\n", &i);

		for(int j = 0; j <= i; ++j)
			scanf("%d\n", &cj[j]);

		scanf("%d %d\n", &d, &k);
		
		int n;

		for(n = 1; d * n * (n + 1) / 2  < k; n++);

		ull sum = 0;

		for(int  j = 0; j <= i; ++j)
			sum += cj[j] * (ull) pow(n, j);

		printf("%llu\n", sum);
	}
}