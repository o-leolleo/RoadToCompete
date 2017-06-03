#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
map<int,int> A;
bitset<MAX>pares;
int Msb, Massa;

int msb(int x) {
	int k=-1; while(x) {x>>=1; k++;}
	return k;
}

long long backtrack(int c1, int c2, int k, int x)
{
	long long ans = 0;

	if ((c1 ^ c2) > x || c1 > Massa || c2 > Massa) return 0;

	if ((c1 ^ c2) == x && A.count(c1) && A.count(c2) && !pares[c1] && !pares[c2]) {
		ans += (c1 == c2) ? (A[c1]-1)*((long long)(A[c1]))/2 : (long long)(A[c1])*A[c2];
		pares[c1] = pares[c2] = true;
		if (k > Msb) return ans;
	}

	if (k > Msb) return 0;

	if (x & (1 << k)) {
		c1 |= (1 << k);
		c2 &= ~(1 << k);
		ans += backtrack(c1,c2,k+1,x);
		c1 &= ~(1 << k);
		c2 |= (1 << k);
		ans += backtrack(c1,c2,k+1,x);
	} else {
		c1 &= ~(1 << k);
		c2 &= ~(1 << k);
		ans += backtrack(c1,c2,k+1,x);
		c1 |= (1 << k);
		c2 |= (1 << k);
		ans += backtrack(c1,c2,k+1,x);
	}

	return ans;
}

int main()
{
	int n, x;
	Msb = Massa = -1;

	scanf("%d %d\n", &n, &x);

	for (int i = 0; i < n; ++i) {
		int tmp;

		scanf("%d\n", &tmp);

		Msb = max(Msb, msb(tmp));
		Massa = max(Massa, tmp);

		if (!A.count(tmp))
			A[tmp] = 1;
		else
			A[tmp]++;
	}

	printf("%lld\n",backtrack(0,0,0,x));	
}

