#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
vector<vii> A;
int dist[100010];
bool is_v[100010];

int dfs(int u)
{
	int ans = 0;
	for (int j = 0; j < A[u].size(); ++j) {
		ii v = A[u][j];
		dist[v.first] = v.second + dist[u];
		if (is_v[v.first]) ans += v.second;
		int check = dfs(v.first);
		ans += check;
		if (check && !is_v[v.first]) ans += v.second;
	}
	return ans;
}

int main()
{
	int N, F;

	scanf("%d %d\n", &N, &F);
	memset(dist, -1, sizeof dist);
	memset(is_v, false, sizeof is_v);

	A.assign(N + 1, vii());

	for (int i = 0; i < N - 1; ++i) {
		int a, b, w;
		scanf("%d %d %d\n", &a, &b, &w);
		a--; b--;
		A[a].push_back(ii(b,w));
	}

	for (int i = 0; i < F; ++i) {
		int tmp; scanf("%d\n", &tmp); tmp--;
		is_v[tmp] = true;
	}

	dist[0] = 0;
	int sum = dfs(0), maior = -1;

	for (int v = 0; v < N; ++v)
		if (is_v[v] && dist[v] > maior)
			maior = dist[v];

	printf("%d\n", sum - maior);
}
