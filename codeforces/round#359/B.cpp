#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, a[110], op;
	int stk[110], top = -1;
	
	scanf("%d\n", &n);

	for (int i = 0; i < n; ++i) scanf("%d\n", &a[i]);
	
	for (int x = 0; x < 20000;) {
		top = -1;

		for (int i = 1; i <= n; ++i) {
			if (i < n && a[i-1] > a[i]) {
				stk[++top] = i;
			} else if (top >= 0) {
				printf("%d %d\n", top%2 == 0? stk[0] : stk[1], stk[top]+1); 
				while (top >= 0) {
					swap(a[stk[top]-1],a[stk[top]]);
					x++; top-=2;
				}
				top = -1;
			}
		}

		op = 0;
		for (op = 1; op < n; ++op) if (a[op-1] > a[op]) break;
		if (op == n) break;
	}
}
