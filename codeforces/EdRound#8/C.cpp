#include <bits/stdc++.h>
using namespace std;
#define MAX 100010

pair<char, int> str[MAX];
int n, max_dist[MAX];

bool comp(pair<char, int> a, pair<char, int> b)
{
	return max(abs(a.first - 'a'), abs('z' - a.first)) > max(abs(b.first - 'a'), abs('z' - b.first));
}

int main()
{
	int k;
	char _str[MAX], aux[MAX];

	scanf("%d %d\n", &n, &k);

	for (int i = 0; i < n; ++i) {
		char a;
		scanf("%c\n", &a);
		str[i].first = a;
		str[i].second = i;
		aux[i] = str[i].first;
	}

	sort(str, str + n, comp);

	for (int i = 0; i < n; ++i)
		max_dist[i] = max(abs(str[i].first - 'a'), abs('z' - str[i].first));

	
	int i = 0;
	
	while (i < n && k - max_dist[i] > 0) {
		if (max_dist[i] == str[i].first - 'a')
			_str[str[i].second] = 'a';
		else
			_str[str[i].second] = 'z';
		k -= max_dist[i++];		
	}

	if (i == n && k > 0) {
		printf("-1\n");	
		exit(0);
	}

	_str[str[i].second] = str[i].first - 'a' + k <= 25 ? str[i].first + k : str[i].first - k;
	i++;

	while (i < n)
		_str[str[i].second] = str[i].first, i++;

	_str[n] = '\0';
	printf("%s\n", _str);
}
