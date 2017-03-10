#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
#define MAX 110
ii pass[MAX];

int main()
{
	int n, s;

	scanf("%d %d\n", &n, &s);

	for (int i = 0; i < n; ++i)
		scanf("%d %d\n", &pass[i].first, &pass[i].second);

	sort(pass, pass + n);
	reverse(pass, pass + n);
	
	int now = s, sum = 0;

	for (int i = 0; i < n; ++i) {
		if (now != pass[i].first) {
			sum += now - pass[i].first;
			now = pass[i].first;
		}

		if (pass[i].second > sum)
			sum = pass[i].second;

	}

	sum += now;

	printf("%d\n", sum);
}
