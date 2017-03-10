#include <bits/stdc++.h>
using namespace std;
#define MAX 60
int main()
{
	int A[MAX][MAX], N, P[MAX];
	bool num[MAX];
	scanf("%d\n", &N);

	memset(P, -1, sizeof P);
	memset(num, false, sizeof num);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			scanf("%d\n", &A[i][j]);

	for (int i = 0; i < N; ++i) {
		int cont = 0, aux[N + 1];
		memset(aux, 0, sizeof aux);
		
		for (int j = 0; j < N; ++j)
			aux[A[i][j]]++;
		
		int M = -1, k = -1;

		for (int j = 1; j <= N; ++j)
			if (aux[j] >= M)
				M = aux[j], k = j;

		P[i] = k;

		for (int j = 0; j < i; ++j)
			if (P[j] == P[i]) P[i] = N;
	}
	
	for (int i = 0; i < N; ++i)
		printf("%d%c", P[i], i + 1 == N ? '\n' : ' ');
}
