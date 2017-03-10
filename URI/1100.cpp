#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define MAX 9
int chess[MAX][MAX][MAX][MAX], dist[MAX][MAX], 
dx[] = {1, -1, -1, 1, 2, 2, -2, -2},
dy[] = {2, 2, -2, -2, 1, -1, 1, -1};

int main()
{
	char p1[4], p2[4];
	queue<ii> q;

	for (int a = 0; a < 8; ++a)
		for (int b = 0; b < 8; ++b)
		{
			memset(dist, -1, sizeof dist);

			q.push(ii(a,b));
			dist[a][b] = 0;

			while(!q.empty()) {
				ii u = q.front(); q.pop();

				for (int k = 0; k < 8; ++k) {
					int x = u.first + dx[k], y = u.second + dy[k];

					if (x >= 0 && y >= 0 && x < 8 && y < 8 && dist[x][y] < 0) {
						dist[x][y] = dist[u.first][u.second] + 1;
						q.push(ii(x, y));
					}
				}
			}

			for (int x = 0; x < 8; ++x)
				for (int y = 0; y < 8; ++y)
					chess[a][b][x][y] = dist[x][y];
		}

	while (scanf("%s %s\n", p1, p2) != EOF) {
		int x1, y1, x2, y2;
		y1 = p1[0] - 'a';
		x1 = p1[1] - '0';
		y2 = p2[0] - 'a';
		x2 = p2[1] - '0';
		x1--;x2--;
		printf("To get from %s to %s takes %d knight moves.\n", p1, p2, chess[x1][y1][x2][y2]);
	}
}
