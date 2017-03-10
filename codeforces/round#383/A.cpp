#include<bits/stdc++.h>
using namespace std;

int modPow(int a, int n, int p)
{
	if (n == 0) return 1;	

	if (n % 2 == 0) {
		int u = modPow(a,n/2,p);
		return (u * u) % p;
	} 
	
	return (a * modPow(a,n-1, p))%p;
}

int main()
{
	int n;
	scanf("%d\n", &n);
	printf("%d\n", modPow(1378, n, 10));
}
