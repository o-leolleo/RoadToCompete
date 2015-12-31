#include <bits/stdc++.h>
using namespace std;
#define MAX 40000
int info[MAX], t;
bool st[MAX];

void dfs(int s)
{
	if (st[s]) return;
	st[s] = true;
	dfs(s + info[s]);
}

int main()
{
	int n;

	scanf("%d %d\n", &n, &t);

	for (int i = 1; i <= n - 1; ++i) scanf("%d\n", &info[i]);
	memset(st, false, sizeof st);	
	dfs(1);

	printf("%s\n", st[t] ? "YES" : "NO");
}
