#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T, A[2][2], B[2][2];

	scanf("%d\n", &T);

	for (int k = 1; k <= T; ++k) {
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				scanf ("%d\n", &A[i][j]);
		
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				scanf ("%d\n", &B[i][j]);
	
		int c;

		for (c = 0; c < 4; ++c)
			if (
				B[0][0] == A[0][0] &&
				B[0][1] == A[0][1] &&
				B[1][0] == A[1][0] &&
				B[1][1] == A[1][1] ) 
				break;
			else {
				int C[2][2];
				C[0][0] = B[1][0];
				C[0][1] = B[0][0];
				C[1][0] = B[1][1];
				C[1][1] = B[0][1];

				for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j)
					B[i][j] = C[i][j];
			}

		printf("Case #%d: %s\n", k, c == 4 ? "IMPOSSIBLE" : "POSSIBLE");
	}
}
