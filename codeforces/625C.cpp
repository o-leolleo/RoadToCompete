#include <bits/stdc++.h>
using namespace std;
#define MAX 510

int main()
{
	int n, k, grid[MAX][MAX], m, M;

	scanf("%d %d\n", &n, &k);
	m = 1; M = n * n; k--;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < k; ++j)
			grid[i][j] = m++;

	for (int i = 0; i < n; ++i)
		for (int j = n - 1; j >= k; --j)
			grid[i][j] = M--;

	int sum = 0;

	for (int i = 0; i < n; ++i)
		sum += grid[i][k];


	printf("%d\n",sum);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			printf("%d%c", grid[i][j], j + 1 == n ? '\n' : ' ');
}
