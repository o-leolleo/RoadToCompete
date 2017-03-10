#include <bits/stdc++.h>
using namespace std;
#define MAXN 25
#define MAXM 55

int A[MAXM][MAXN], B[MAXM];

int main()
{
	int N, M, sumd = 0;
	scanf("%d %d\n", &N, &M);

	for (int i = 0; i < M; ++i) {
		scanf("%d\n", &B[i]);

		for (int j = 0; j < N; ++j) {
			scanf("%d\n", &A[i][j]);
			if (j > 0) A[i][j] += A[i][j - 1];
		}

		if (A[i][N-1] <= B[i]) sumd += A[i][0];
	}

	int sume = 0;

	for (int i = 0; i < M; ++i) {
		int pot = 1, m = -1;	

		for (int j = 0; j <= 4; j++, pot *= 10) {
			if(pot + A[i][N-1] - A[i][0] <= B[i]) 
				m = pot;
		}

		if (m >= 0) sume += m;
	}

	printf("%d\n", sume - sumd);
}
