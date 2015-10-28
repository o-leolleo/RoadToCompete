#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll loto[10010];

int main()
{
	int N, K;
	scanf("%d %d\n", &N, &K);

	for (int i = 0; i < N; ++i) {
		loto[i] = 0;
		for (int j = 0; j < K; ++j) {
			int tmp; scanf("%d\n", &tmp);
			if (tmp % 2 == 1) loto[i] |= (1ll << (K - j - 1));
		}
	}

	for (int c = 0; c < K; ++c) {
		int pos = -1;
		ll maior = 0;

		for (int l = c; l < N; ++l)
			if (loto[l] > maior) {
				maior = loto[l];
				pos = l;
			}

		if (pos >= 0) {
			ll tmp    = loto[pos];
			loto[pos] = loto[c];
			loto[c]   = tmp;

			for (int l = c + 1; l < N; ++l)
				if ((loto[l] ^ loto[c]) < loto[l])
					loto[l] = (loto[l] ^ loto[c]);
		}
	}

	int n = 0;
	while (n < N && loto[n]) n++;

	if ((n == K) && (n < N)) printf("N\n");
	else printf("S\n");
}
