#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k;
ll dp[55][55];
ll bar(ll n, ll k) {
	if (k == 0 && n > 0) return 0;
	if (n == 0 && k == 0) return 1;
	if (dp[n][k] != -1) return dp[n][k];
	ll &ans = dp[n][k]; ans = 0;
	for (ll v = 1; v <= m; ++v)
		if (v <= n) ans += bar(n - v, k - 1);
	return ans;
}
int main()
{
	while (scanf("%lld %lld %lld\n", &n, &k, &m) != EOF) {
		memset(dp, -1, sizeof dp);
		printf("%lld\n", bar(n, k));
	}
}
