#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned ll;
int main()
{
	ll dp[6][30010]; int cents[] = { 0, 1, 5, 10, 25, 50 }, money = 30000;

	for (int i = 0; i <= 5; ++i) dp[i][0] = 1;
	for (int i = 0; i <= money; ++i) dp[0][i] = 0;

	for (int id = 1; id <= 5; ++id)
		for (int M = 1; M <= money; ++M)
			if (cents[id] > M)
				dp[id][M] = dp[id - 1][M];
			else
				dp[id][M] = dp[id - 1][M] + dp[id][M - cents[id]];

	while (scanf("%d\n", &money) != EOF) {
		printf("There %s %llu way%sto produce %d cents change.\n",
			dp[5][money] == 1 ? "is only" : "are",
			dp[5][money],
			dp[5][money] == 1 ? " " : "s ",
			money
		);
	}
}
