#include <bits/stdc++.h>
using namespace std;
#define MAX 200010
int a[MAX], p[MAX];

bool comp(int a, int b) {
	return a > b;
}

int main()
{
	int n, m;
	scanf("%d %d\n", &n, &m);
	memset(p, 0, sizeof p);

	for (int i = 0; i < n; ++i)
		scanf("%d\n", &a[i]);

	for (int i = 0; i < m; ++i) {
		int t, r;
		scanf("%d %d\n", &t, &r);
		if (t == 1) {
			p[r] = 1;
		} else {
			p[r] = 2;
		}
	}

	for (int i = 0; i < n; ++i)
		printf("%d%c", a[i], i + 1 == n ? '\n' : ' ');
}
