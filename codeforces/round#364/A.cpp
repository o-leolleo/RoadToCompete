#include <bits/stdc++.h>
using namespace std;

int main()
{
	pair<int, int> card[110];
	int n;
	scanf("%d\n", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d\n", &card[i].first);
		card[i].second = i;
	}

	sort(card, card + n);
	
	for (int k = 0; k < n/2; ++k)
		printf("%d %d\n", card[k].second + 1, card[n - 1 - k].second + 1); 
}
