#include <bits/stdc++.h>
using namespace std;
#define MAX 5010
int r[2][MAX], c[2][MAX];

int main()
{
	int m, n;
	scanf("%d %d\n", &n, &m);

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < MAX; ++j) {
			r[i][j] = 0;
			c[i][j] = 0;
		}

	int k;
	scanf("%d\n", &k); 

	for (int op = 1; op <= k; ++op) {
		int t, x, y; scanf("%d %d %d\n", &t, &x, &y);

		if (t == 1) {
			r[0][x-1] = y;
			r[1][x-1] = op; 
		} else {
			c[0][x-1] = y;
			c[1][x-1] = op;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (r[1][i] > c[1][j]) printf("%d%c", r[0][i], j + 1 == m ? '\n' : ' ');	
			else printf("%d%c", c[0][j], j + 1 == m ? '\n' : ' '); 
		}
	}
}
