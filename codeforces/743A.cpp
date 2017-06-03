#include <bits/stdc++.h>
using namespace std;
#define MAX 100100

typedef pair<int, int> ii;
int air[MAX], dist[MAX];
bool owner[MAX];

int lenght(int u, int v)
{
	return owner[u] == owner[v] ? 0 : abs(u - v);
}

int main()
{
	int n, a, b;

	scanf("%d %d %d\n", &n, &a, &b);

	for (int i = 0; i < n; ++i) {
		char tmp; scanf("%c\n", &tmp);
		owner[i] = tmp - '0';
	}

	a--; b--;

	if (owner[a] == owner[b]) printf("0\n");
	else {
		int index_m, m = 999999999;

		for (int i = 0; i < n; ++i) if (i!=a && owner[i] != owner[a]) {
			if (abs(i-a) < m) {
				index_m = i;
				m = abs(i-a);
			}
		}

		a = index_m;
	
		for (int i = 0; i < n; ++i) if (i!=a && owner[i] != owner[a]) {
			if (abs(i-a) < m) {
				index_m = i;
				m = abs(i-a);
			}
		}

		printf("%d\n", m);
	}
}
