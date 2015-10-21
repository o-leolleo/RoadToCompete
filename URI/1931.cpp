#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef pair<int, ii> iii;
#define F first
#define S second
#define INF 99999999
vector<vii> A;
vi dist[2];
priority_queue< iii, vector<iii>, greater<iii> > pq;

int main()
{
	int C, V;
	scanf("%d %d\n", &C, &V);

	A.assign(C + 1, vii());
	dist[0].assign(C + 1, INF);
	dist[1].assign(C + 1, INF);

	for (int i = 0; i < V; ++i) {
		int u, v, w;
		scanf("%d %d %d\n", &u, &v, &w);
		A[u].push_back(ii(v, w));
		A[v].push_back(ii(u, w));
	}

	pq.push(iii(0,ii(0,1)));
	dist[0][1] = 0;
	dist[1][1] = INF;

	while (!pq.empty()) {
		iii front = pq.top(); pq.pop();
		int d = front.F;
		ii  u = front.S;

		if (d > dist[u.F][u.S]) continue;

		for (int j = 0; j < A[u.S].size(); ++j) {
			ii v = A[u.S][j];

			if (dist[u.F][u.S] + v.S < dist[!u.F][v.F]) {
 				dist[!u.F][v.F] = dist[u.F][u.S] + v.S;
				pq.push(iii(dist[!u.F][v.F], ii(!u.F, v.F)));
			}
		}
	}

	if (dist[0][C] != INF) printf("%d\n", dist[0][C]);
	else printf("-1\n", dist[1][C]);
}
