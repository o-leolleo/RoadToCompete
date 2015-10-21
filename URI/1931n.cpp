#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector<vii> A;
priority_queue<ii, vector<ii>, greater<ii> > pq;
vi dist;
#define INF 99999999

int main()
{
	int C, V;
	scanf("%d %d\n", &C, &V);
	A.assign(C + 1, vii());
	dist.assign(C + 1, INF);

	for (int i = 0; i < V; ++i) {
		int u, v, w;
		scanf("%d %d %d\n", &u, &v, &w);
		A[u].push_back(ii(v, w));
		A[v].push_back(ii(u, w));
	}

	pq.push(ii(0,1));
	dist[1] = 0;

	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;

		if (d > dist[u]) continue;

		for (int j = 0; j < A[u].size(); ++j) {
			ii v = A[u][j];

			for (int k = 0; k < A[v.first].size(); ++k) {
				ii w = A[v.first][k];

				if (dist[u] + v.second + w.second < dist[w.first]) {
					dist[w.first] = dist[u] + v.second + w.second;
					pq.push(ii(dist[w.first], w.first));
				}
			}
		}
	}

	if (dist[C] != INF) printf("%d\n", dist[C]);
	else printf("-1\n");
}
