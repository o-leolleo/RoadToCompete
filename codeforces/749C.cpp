#include <bits/stdc++.h>
using namespace std;
#define MAX 200100

void print(int *c, int n){
	for (int i = 0; i < n; ++i) printf("%d ", c[i]);
	printf("\n");
}

int main()
{
	int n, d, r, D[MAX], R[MAX], tmpD[MAX], tmpR[MAX];
	char votes[200100];

	d = r = 0;

	scanf("%d\n", &n);
	scanf("%s\n", votes);

	for (int i = 0; i < n; ++i) D[i] = R[i] = -1;

	for (int i = 0; i < n; ++i)
		if (votes[i] == 'D') { 
			D[i] = i;
			tmpD[d] = i;
			d++;
		} else {
			R[i] = i;
			tmpR[r] = i;
			r++;
		}

	int k = 0;
	for (int i = 0; i < d; ++i)
		while (k < n && k < tmpD[i]) {
			D[k] = tmpD[i];
			k++;
		}

	while (k < n) D[k++] = D[0];
		
	k = 0;
	for (int i = 0; i < r; ++i)
		while (k < n && k < tmpR[i]) {
			R[k] = tmpR[i];
			k++;
		}

	while (k < n) R[k++] = R[0];

	print(D, n);
	print(R, n);

	while (k < n) R[k++] = R[0];

	while (r > 0 && d > 0) {
		for (int i = 0; i < n; ++i)
			if (votes[i] != '.')
				if (votes[i] == 'D') {
					votes[D[i]] = '.';
					D[D[i]] = D[(D[i]+1)%n];
					d--;
				} else {
					votes[R[i]] = '.';
					R[R[i]] = R[(R[i]+1)%n];
					r--;
				}
	}

	if (r > 0) printf("R\n");
	else printf("D\n");
}
