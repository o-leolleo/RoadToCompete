#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int find(int n, ll k)
{
	ll mid = (ll)((pow(2,n)-1)/2)+1;
	if (k == mid) return n;
	if (k > mid) k -= mid;
	find(n-1,k);
}
int main()
{
	int n;
	ll k;

	scanf("%d %lld\n", &n, &k);
	printf("%d\n", find(n, k));
}
