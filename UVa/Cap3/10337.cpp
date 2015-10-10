#include <bits/stdc++.h>
using namespace std;
int W[15][1010], dp[15][1010], X;
int flight(int mile, int high) {
	if (high > X - mile) return 9999999;
	if (mile == X) return high == 0 ? 0 : 9999999;
	if (dp[high][mile] != -1) return dp[high][mile];
	int &ans = dp[high][mile];
	int p1 = high + 1 <= 9 ? 60 - W[high][mile] + flight(mile + 1, high + 1) : 9999999,
	    p2 = high - 1 >= 0 ? 20 - W[high][mile] + flight(mile + 1, high - 1) : 9999999,
	    p3 = 30 - W[high][mile] + flight(mile + 1, high);
	ans = min(min(p1, p2), p3);
	return ans;
}

int main()
{
	int N;
	scanf("%d\n", &N);
	while (N--) {
		scanf("%d\n", &X); X /= 100;
		for (int a = 0; a < 10; ++a)
			for (int b = 0; b < X; ++b)
				scanf("%d\n", &W[9 - a][b]);
		memset(dp, -1, sizeof dp);
		printf("%d\n\n", flight(0,0));
	}
}
