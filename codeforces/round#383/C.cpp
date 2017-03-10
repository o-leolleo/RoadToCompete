#include <bits/stdc++.h>
using namespace std;
#define MAX 200
int  crush[MAX];
bool color[MAX], has_loop;

int main()
{
	int n;

	scanf("%d\n", &n);
	memset(color, false, sizeof color);

	for (int i = 0; i < n; ++i) {
		scanf("%d\n", &crush[i]);
		crush[i]--;
	}

	int t = -1;
	memset(color, false, sizeof color);

	for (int i = 0; i < n; ++i) {
		int next = i;

		while (!color[next]) {
			color[next] = true;
			next = crush[next];
		}

		if (next != crush[next]) {
			int j = crush[next], p = 1;		
			while (j != next) { j = crush[j]; p++; }
			if (p == 2) p = 1;
			t = max(t, p);	
		}
	}

	printf("%d\n", t);
}
