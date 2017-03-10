#include <bits/stdc++.h>
using namespace std;

int main()
{
	int point[3][2];

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 2; ++j)
			scanf("%d\n", &point[i][j]);
	
	printf("3\n");

	for (int i = 0; i < 3; ++i) {
		int u[2], v[2];
		
		u[0] = point[(i+1)%3][0] - point[i][0];
		u[1] = point[(i+1)%3][1] - point[i][1];

		v[0] = point[(i+2)%3][0] - point[i][0];
		v[1] = point[(i+2)%3][1] - point[i][1];

		printf("%d %d\n", u[0] + v[0] + point[i][0], u[1] + v[1] + point[i][1]);
	}
}
