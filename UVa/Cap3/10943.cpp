#include <bits/stdc++.h>
using namespace std;
#define P 1000000
#define MAX 210
int N, K, C[MAX][MAX];

int main()
{
	for (int n = 0; n < MAX; ++n) C[n][0] = C[n][n] = 1;
	for (int n = 2; n < MAX; ++n)
		for (int k = 1; k < n; ++k)
			C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % P;

	while (scanf("%d %d\n", &N, &K), N) {
		printf("%d\n", C[N + K - 1][K - 1]);
	}
}
