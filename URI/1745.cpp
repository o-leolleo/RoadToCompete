#include <bits/stdc++.h>
using namespace std;
#define LEN 1000100
int num[LEN], tam, dp[LEN][3], N;

int check(int id, int sum)
{
	if (id == tam) return 0;
	if (sum >= 0 && dp[id][sum] != -1) return dp[id][sum];
	int &ans = dp[id][sum];
	return ans = (int)((sum + num[id]) % 3 == 0) + check(id + 1, (sum + num[id]) % 3)
	+ check(id + 1, 0);
}

int main()
{
	char S[LEN]; int i;
	memset(dp, -1, sizeof dp);
	tam = 0; i = 0;

	while (scanf("%c\n", &S[i]) != EOF) {
		if (isdigit(S[i])) num[tam++] = (S[i] - '0') % 3;
		i++;
	}
	printf("%d\n", check(0, 0));
}
