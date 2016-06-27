#include <bits/stdc++.h>
using namespace std;
#define MAX 200200
int main()
{
	int N, x[MAX];

	while (scanf("%d\n", &N) != EOF) {
		x[0] = 0;

		for (int i = 1; i <= N; ++i) { 
			scanf("%d\n", &x[i]);
			x[i] += x[i-1];
		}


		if (x[N] % 3 == 0) {
			int cont = 0;

			for (int i = 1; i <= N && x[i-1] < x[N] / 3; ++i) {
				int pos = lower_bound(x + i, x + N + 1, x[i-1] + x[N] / 3) - x;

				if ((x[pos] == x[i-1] + x[N] / 3) && (pos != N + 1)) {
					int old = pos;
					pos = lower_bound(x + pos + 1, x + N + 1, x[pos] + x[N] / 3) - x;
					if ((pos != N + 1) && (x[pos] == x[old] + x[N] / 3)) cont++;
				}
			}

			printf("%d\n", cont);
		} else
			printf("0\n");
	}
}

