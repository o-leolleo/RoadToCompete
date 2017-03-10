#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int main()
{
	int n, q, server[200], disp = 0;
	scanf("%d %d\n", &n, &q);
	memset(server, 0, sizeof server);
	disp = n;

 	while (q--) {
		int t, k, d, disp = 0;
		scanf("%d %d %d\n", &t, &k, &d);

		for (int i = 0; i < n; ++i)
			if (server[i] < t) {
				server[i] = 0;
				disp++;
			}

		if (disp >= k) {
			int s = 0;
			disp = 0;
			for (int i = 0; disp < k && i < n; ++i) if (server[i] < t) {
				s += i+1;
				disp++;
				server[i] = t + d - 1;
			}
			printf("%d\n", s);
		} else
			printf("-1\n");
	}
}
