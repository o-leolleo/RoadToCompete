#include <bits/stdc++.h>
using namespace std;
#define MAX 2010
int train[MAX], LIS[MAX], LDS[MAX];

int main()
{
	int n, t;
	scanf("%d\n", &t);

	while(t--) {
		scanf("%d\n", &n);
		int N = 0;

		if (n) {
			for (int i = 0; i < n; ++i)
				scanf("%d\n", &train[n - i - 1]);

			for (int i = 0; i < n; ++i) {
				LIS[i] = 1; LDS[i] = 1;
				for (int j = 0; j < i; ++j) {
					if (train[j] < train[i])
						LIS[i] = max(LIS[i], LIS[j] + 1);
					if (train[j] > train[i])
						LDS[i] = max(LDS[i], LDS[j] + 1);
				}
			}

			N = -1;
			for (int i = 0; i < n; ++i)
				N = max(N, LIS[i] + LDS[i] - 1);
		}
		printf("%d\n", N);
	}
}
