#include<bits/stdc++.h>
using namespace std;
#define MAX 500

char grid[MAX][MAX];
int n, m;

bool null_line(int i, int j, int lim)
{
	for (int k = j; k < lim; ++k)
		if (grid[i][k] != '.') return false;
	return true;
}

int main()
{

	scanf("%d %d\n", &n, &m);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%c\n", &grid[i][j]);

	int a, b;
	bool ans = true;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (grid[i][j] == 'X')
				a = i, b = j, i = n, j = m;

	for (int j = 0; j < m; ++j)
		for (int i = 0; i < n; ++i)
			if (grid[i][j] == 'X') {
				if (i != a || j != b)
					ans = false;
				i = n, j = m;
			}

	if (ans) {
		int c;

		for (c = b; c < m && grid[a][c] == 'X'; ++c);

		for (int i = a + 1; i < n; ++i) {
			int j;

			for (j = b; j < m && grid[i][j] == 'X'; ++j);

			if (j != c && !null_line(i, b, c)) {
				ans = false;
				break;
			} else if (null_line(i, b, c))
				break;
		}
	}

	printf("%s\n", ans ? "YES" : "NO");
}
