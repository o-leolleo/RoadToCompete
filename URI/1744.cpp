#include <bits/stdc++.h>
using namespace std;
#define MAX 5010
int main()
{
	char S[MAX]; int A, B;
	scanf("%d %d\n", &A, &B);
	int N, lim; N = lim = 0;

	while (scanf("%c\n", &S[N]) != EOF)
		if (S[N++] == 'B') lim++;

	int cost = 0;

	for (int p = lim; p < N; ++p) {
		int j = p - 1; bool opa = false;
		if (S[p] == 'B') {
			while (j >= 0 && (p - j) * (A - B) <= A)
				if (j < lim && S[j] == 'W') {
					opa = true;
					cost += (p - j) * (A - B);
					S[j] = 'B';
					break;
				} else
					j--;

			if (!opa) cost += A;
			S[p] = 'W';
		}
	}
	printf("%d\n", cost);
}
