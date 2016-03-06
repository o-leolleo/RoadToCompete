#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
typedef long long ll;
ll even[MAX], odd[MAX];

int main()
{
	int n, e, o;
	e = o = 0;
	scanf("%d\n", &n);

	for (int i = 0; i < n; ++i) {
		ll tmp;
		scanf("%lld\n", &tmp);
		if (tmp % 2 == 0) even[e++] = tmp;
		else odd[o++] = tmp;
	}
	
	sort(odd, odd + o);
	reverse(odd, odd + o);
	ll sum = 0;

	for (int i = 0; i < e; ++i)
		sum += even[i];

	int lim = (o % 2 == 0 ?	o : o - 1);

	for (int i = 0; i < lim; ++i)
		sum += odd[i];

	printf("%lld\n", sum);
}
