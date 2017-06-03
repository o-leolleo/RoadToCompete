#include <bits/stdc++.h>
using namespace std;

int A[6], B[6];
    

int main () {
	int n; scanf("%d\n", &n);

	memset(A, 0, sizeof A);
	memset(B, 0, sizeof B);

	for (int i = 0; i < n; ++i) {	
		int tmp; scanf("%d\n", &tmp);	
		tmp--; A[tmp]++;
	}

	for (int i = 0; i < n; ++i) {	
		int tmp; scanf("%d\n", &tmp);	
		tmp--; B[tmp]++;
	}

	int ex = 0, sumB = 0, sumA = 0;

	for (int i = 0; i < 5; ++i) {
		if ((A[i] + B[i])%2!=0) {
			ex = -1; break;
		}
		
		if (A[i]-B[i]<0) {
			sumB += abs(A[i]-B[i])/2;
		} else if (A[i]-B[i]>0) {
			sumA += abs(A[i]-B[i])/2;
		}
	}
	
	if (!ex) ex = !(sumA -  sumB) ? sumA : -1;
	printf("%d\n", ex);
}	
