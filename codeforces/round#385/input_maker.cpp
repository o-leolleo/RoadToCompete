#include<bits/stdc++.h>
using namespace std;

void show(char grid[510][510], int n, int m)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			printf("%c", grid[i][j]);
		printf("\n");
	}
}

int main()
{
	int n, m;
	char grid[510][510];
	FILE* file;

	file = fopen("temp.txt", "w+");

	scanf("%d %d", &n, &m);

	for (int i = 0; i < 510; ++i)
		for (int j = 0; j < 510; ++j)
			grid[i][j] = 'X';

	int a, b, d, e;

	do {
		scanf("%d %d %d %d", &a, &b, &d, &e);
		if (a >= 0) {
			for (int i = a; i <= d; ++i)
				for (int j = b; j <= e; ++j)
					grid[i][j] = '.';
			show(grid,n,m);
		}
	} while (a >= 0);

	for (int i = 0; i < n; ++i)
		fprintf(file, "%s\n", grid[i]);
}
