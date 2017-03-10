#include <bits/stdc++.h>
using namespace std;
#define MAX 202000

typedef long long ll;

vector<bool> visited;
vector< vector<int> > AdjLst;
ll  som[MAX], ple[MAX], choosen[2];

void attrib(ll candidate)
{
	for (int i = 0; i < 2; ++i)
		if (candidate > choosen[i]) {
			choosen[i] = candidate;
			break;
		}
}

void dfs(int u) {
	int n = 0;

	visited[u] = true;
	som[u] = ple[u];
	printf("in : %d->%lld\n", u, som[u]);

	for (int k = 0; k < AdjLst[u].size(); ++k) {
		int v = AdjLst[u][k];
		
		if (!visited[v]) {
			dfs(v);
			n++;
		}
	
		som[u] += som[v];
	}

	if (n > 1)
		for (int i = 0; i < AdjLst[u].size(); ++i) 
			if (AdjLst[u][i] != u)
				attrib(som[AdjLst[u][i]]);

	printf("%d->%lld\n", u+1, som[u]);
}

int main()
{
	int n; 

	scanf("%d\n", &n);

	AdjLst.assign(n, vector<int>());
	visited.assign(n, false);

	memset(som, 0, sizeof som);
	choosen[0] = choosen[1] = -1999999999;

	for (int i = 0; i < n; ++i)
		scanf("%lld\n", &ple[i]);

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d %d\n", &u, &v);
		AdjLst[u-1].push_back(v-1);
		AdjLst[v-1].push_back(u-1);
	}

	dfs(0);

	if (choosen[1] == -1999999999)
		printf("Impossible\n");
	else
		printf("%lld\n", choosen[0] + choosen[1]);
}
