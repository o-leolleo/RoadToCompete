#include <bits/stdc++.h>
using namespace std;
#define MAX 110
bool bar[MAX];
typedef long long ll;
ll dp[MAX][2];
int N;

ll cut(int k, bool f)
{
	if (k == N) return f;
	if (dp[k][f] >= 0) return dp[k][f];
	if (f) return dp[k][f] = bar[k] ? 0 : cut(k + 1, false) + cut(k + 1, true);
	return dp[k][f] = bar[k] ? cut(k + 1, false) + cut(k + 1, true) : cut(k + 1, false);
}

int main()
{
	scanf("%d\n", &N);

	for (int i = 0; i < N; ++i) scanf("%d\n", &bar[i]);
	memset(dp, -1, sizeof dp);
	printf("%lld\n", cut(0, false));
}
