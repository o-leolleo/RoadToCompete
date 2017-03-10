#include <bits/stdc++.h>
using namespace std;
#define MAX 100100
int M, N, cont;
int dist[MAX];

int main()
{
	scanf("%d %d\n", &N, &M);
	memset(dist, -1, sizeof dist);

	queue<int> q;
	q.push(N);
	dist[N] = 0;
	
	while (!q.empty()) {
		int u = q.front(); q.pop();

		if (u < M) {
			if (u > 0 && dist[u-1] < 0) {
				dist[u-1] = dist[u] + 1;
				q.push(u-1);
			}

			if (dist[2 * u] < 0) {
				dist[2 * u] = dist[u] + 1;
				q.push(2 * u);
			}
		} else if (u > M) {
			if (u > 0 && dist[u - 1] < 0) {
				dist[u-1] = dist[u] + 1;
				q.push(u-1);
			}
		} else
			break;
	}

	printf("%d\n", dist[M]);
}
