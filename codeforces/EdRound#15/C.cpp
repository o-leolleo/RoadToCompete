#include <bits/stdc++.h>
using namespace std;
#define MAX 100100
typedef long long ll;

int main()
{
	int n, m; ll a[MAX], b[MAX], max_a, max_b, min_a, min_b;

	max_a = max_b = -1000000010; 
	min_a = min_b =  1000000010;

	scanf("%d %d\n", &n, &m);

	for (int i = 0; i < n; ++i) {
		scanf("%lld\n", &a[i]); 
		max_a = max(max_a, a[i]);
		min_a = min(min_a, a[i]);
	}

	for (int i = 0; i < m; ++i) {
		scanf("%lld\n", &b[i]);
		max_b = max(max_b, b[i]);
		min_b = min(min_b, b[i]);
	}


	ll hi = max(abs(max_a - min_b), abs(max_b - min_a)), lo = 0;

	while (lo < hi) {
		ll mid = lo + (hi - lo) / 2, k = 0, i = 0, cnt = 0;

		while (k < n && i < m) {
			if (a[k] >= b[i] - mid && a[k] <= b[i] + mid)
				cnt++, k++;	
			else if (a[k] > b[i] + mid)
				while (i < m && a[k] > b[i] + mid) i++;
			else
				k++;
		}

		if (cnt == n)
			hi = mid;
		else
			lo = mid + 1;
	}

	printf("%lld\n", hi);
}
