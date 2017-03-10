#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
vector<ii> bc;
vector<int> dest;

bool comp(ii a, ii b)
{
	return a.first < b.first;
}

int main()
{
	int n;

	scanf("%d\n", &n);

	while (n--) {
		int a, b;
		scanf("%d %d\n", &a, &b);
		bc.push_back(ii(a,b));
	}

	sort(bc.begin(), bc.end());

	dest.push_back(0);

	for (int i = 1; i < bc.size(); ++i) {
		int pos = lower_bound(bc.begin(), bc.begin() + i, make_pair(bc[i].first - bc[i].second, 0.0), comp) - bc.begin();	
		dest.push_back(i - pos + (pos > 0 ? dest[pos - 1] : 0));
	}

	int m = bc.size();

	for (int i = 1; i <= bc.size(); ++i) {
		m = min(m, (int)bc.size() - i + dest[i - 1]);
	}

	printf("%d\n", m);
}
