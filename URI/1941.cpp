#include <bits/stdc++.h>
using namespace std;
char str[3010];
int S, spec[3010];
typedef pair<int, int> ii;
ii  dp[3010][3010];

ii pali(int l, int r)
{
	if (l == r) return ii(spec[l], 1);

	if (l + 1 == r) {
		if (str[l] == str[r])
			return ii(spec[l] + spec[r], 2);
		return ii((spec[l] || spec[r]) ? 1 : 0, 1);
	}

	if (dp[l][r].first != -1 && dp[l][r] != -1) return dp[l][r];
	ii &ans = dp[l][r];

	if (str[l] == str[r]) {
		ii p = pali(l + 1, r - 1);
		return ans = ii(spec[l] + spec[r] + p.first, 2 + p.second);
	}

	ii p1 = pali(l + 1, r),
	   p2 = pali(l, r - 1);

	if (p1.first == p2.first)
		return ans = (p1.second > p2.second ? p1 : p2);
	return ans = (p1.first > p2.first ? p1 : p2);
}

int main()
{
	int N = strlen(gets(str));

	scanf("%d\n", &S);
	memset(spec, 0, sizeof spec);
	for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j)
		dp[i][j] = make_pair(-1,-1);

	for (int i = 0; i < S; ++i) {
		int tmp;
		scanf("%d\n", &tmp);
		spec[--tmp] = 1;
	}

	printf("%d\n", pali(0, N - 1).second);
}
