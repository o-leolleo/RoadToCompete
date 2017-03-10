#include <bits/stdc++.h>
using namespace std;
#define MAX 9
#define INF 1000000000
int chess[MAX][MAX][MAX][MAX];
int dl[] = {1, 1, -1, -1, 2, 2, -2, -2},
    dc[] = {2, -2, 2, -2, 1, -1, 1, -1};

int main()
{
	for (int a = 0; a < 8; ++a)
		for (int b = 0; b < 8; ++b)
			for (int x = 0; x < 8; ++x)
				for (int y = 0; y < 8; ++y)
					chess[a][b][x][y] = INF;

	for (int a = 0; a < 8; ++a)
		for (int b = 0; b < 8; ++b) {
			chess[a][b][a][b] = 0;

			for (int k = 0; k < 8; ++k) {
				int x = a + dl[k], y = b + dc[k];
				if (x < 8 && x >= 0 && y < 8 && y >= 0)
					chess[a][b][x][y] = 1;
			}
		}


	for (int kx = 0; kx < 8; ++kx)
		for (int ky = 0; ky < 8; ++ky)
			for (int a = 0; a < 8; ++a)
				for (int b = 0; b < 8; ++b)
					for (int x = 0; x < 8; ++x)
						for (int y = 0; y < 8; ++y)
							chess[a][b][x][y] = min(chess[a][b][x][y], chess[a][b][kx][ky] + chess[kx][ky][x][y]);
	char p1[10], p2[10];

	while(scanf("%s %s\n", p1, p2) != EOF) {
		int x1 = p1[1] - '0',
		    x2 = p2[1] - '0',
		    y1 = p1[0] - 'a',
		    y2 = p2[0] - 'a';

		x1--; x2--;

		printf("To get from %s to %s takes %d knight moves.\n", p1, p2, chess[x1][y1][x2][y2]);
	}
}
