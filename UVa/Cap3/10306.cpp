#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
#define mp make_pair
int main()
{
	int N, dp[310][310]; ii coin[50], cand[300];
	scanf("%d\n", &N);

	while (N--) {
		int M, S, tam = 0;
		scanf("%d %d\n", &M, &S);

		for (int i  = 0; i < M; ++i) {
			int a, b; scanf("%d %d\n", &a, &b);
			coin[i] = mp(a, b);
		}

		for (int x = 0; x <= S; ++x) {
			int y = S * S - x * x;
			if (sqrt(y) == floor(sqrt(y))) {
				cand[tam++] = mp(x, (int)sqrt(y));
			}
		}

		int ans = 999999;

		for (int c = 0; c < tam; c++) {
			ii toTest(cand[c]);
			dp[0][0] = 0;

			for (int x = 0; x <= toTest.first; ++x) {
				for (int y = 0; y <= toTest.second; ++y) {
					if(!x && !y) continue;
					dp[x][y] = 999999;

					for (int i = 0; i < M; ++i)
						if (coin[i].first <= x && coin[i].second <= y)
							dp[x][y] = min(dp[x][y], 1 + dp[x - coin[i].first][y - coin[i].second]);
				}
			}

			ans = min(dp[toTest.first][toTest.second], ans);
		}

		if(ans != 999999) printf("%d\n", ans);
		else printf("not possible\n");
	}
 }
