#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
vector<vii> AdjList;

int main()
{
	int N;

	while (scanf("%d\n", &N) && N) {
		AdjList.assign(N, vii());	

		for (int i = 1; i < N; ++i) {
			int A; ll L; scanf("%d %lld\n", &A, &L);
			AdjList[i].push_back(ii(A, L));
			AdjList[A].push_back(ii(i, L));
		}

		int Q;
		scanf("%d\n", &Q);

		queue<ii> q;
		vector<int> p;
		vector<ll> dist;

		p.assign(N, -1);
		dist.assign(N, -1);
		q.push(ii(0,0));
		p[0] = -1;
		dist[0] = 0;

		while (!q.empty()) {
			ii u = q.front(); q.pop();

			for (int k = 0; k < AdjList[u.first].size(); ++k) {
				ii v = AdjList[u.first][k];

				if (dist[v.first] < 0) {
					dist[v.first] = dist[u.first] + v.second;	
					p[v.first] = u.first;
					q.push(v);
				}
			}
		}

		while (Q--) {
			int S, T;
			scanf("%d %d\n", &S, &T);
			
			int LCA = 0;
			set<int> memo;

			for (int k = S; k >= 0; k = p[k])
				memo.insert(k);

			for (int k = T; k >= 0; k = p[k])
				if (memo.count(k)) {
					LCA = k;
					break;
				}

			printf("%lld%c", dist[S] + dist[T] - 2 * dist[LCA], Q ? ' ' : '\n');
		}
	}
}
