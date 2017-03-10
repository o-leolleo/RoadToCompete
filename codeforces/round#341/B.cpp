#include <bits/stdc++.h>
using namespace std;
#define MAX 200010
long long diag[2*MAX], _diag[2*MAX];

int main()
{
	int n;
	scanf("%d\n", &n);

	memset(diag, 0, sizeof diag);	
	memset(_diag, 0, sizeof _diag);

	for( int i = 0; i < n; ++i) 
	{
		int a, b; scanf("%d %d\n", &a, &b);
		a = 1000 - a + 1;	

		if (b - a >= 0)
			diag[b - a]++;

		else
			diag[1000 + a - b]++;
		
		_diag[a + b - 2]++;
	}

	long long sum = 0;

	for (int i = 0; i <= 200000; ++i) {
		long long n1 = diag[i] * (diag[i] - 1) / 2, n2 = _diag[i] * (_diag[i] - 1) / 2;
		
		if (diag[i]) sum += n1;
		if (_diag[i]) sum += n2;
	}

	printf("%lld\n", sum);
	return 0;
}
