#include <bits/stdc++.h>
using namespace std;
#define MAX 1010
long long a[MAX], b[MAX], M[MAX][MAX], A[MAX][MAX], B[MAX][MAX];

int main()
{
	int n;
	scanf("%d\n", &n);

	for (int i = 0; i < n; ++i)
		scanf("%lld\n", &a[i]);

	for (int i = 0; i < n; ++i)
		scanf("%lld\n", &b[i]);

	long long maior = -1;

	for (int l = 0; l < n; ++l) {
		B[l][l] = b[l];
		A[l][l] = a[l];

		for (int c = l; c < n; ++c) {
			if (c != l)
				maior = max(maior, (b[c] | B[l][c-1]) + (a[c] | A[l][c-1])),
				A[l][c] = a[c] | A[l][c-1],
				B[l][c] = b[c] | B[l][c-1];
			else
				maior = max(maior, b[c]+ a[c]);
		}
	}

	printf("%lld\n", maior);
}
