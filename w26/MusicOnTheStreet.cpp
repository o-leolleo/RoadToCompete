#include <bits/stdc++.h>

using namespace std;
#define MAX 1000010
vector<int> borders;

int freq[MAX], 
	acm[MAX];

int main()
{
	int n, m, h[2];

	scanf("%d\n", &n);

	for (int i = 0; i < n; ++i) {
		int tmp; scanf("%d\n", &tmp);
		borders.push_back(tmp);
	}

	scanf("%d %d %d\n", &m, &h[0], &h[1]);
	memset(freq, 0, sizeof freq);
		
	for (int i = 1; i < n; ++i)
		if (borders[i] - borders[i-1] >= h[0]
		&&  borders[i] - borders[i-1] <= h[1])
			freq[i] = 1;

	acm[0] = 0;
	freq[0] = 1;

	for (int i = 1; i < n; ++i) {
		freq[i] += freq[i-1];
		acm[i] = borders[i] - borders[i-1];
		acm[i] += acm[i-1];
	}

	bool found = false;
	int start_pnt;

	for (int i = 0; !found && i < borders.size(); ++i) {
		int p;

		for (int j = 0; !found && j < 2; ++j) {
			p = borders[i] - h[j];
			if (!i || (p >= borders[i-1])) {
				int pos = lower_bound(acm, acm + n, m + acm[i] - abs(borders[i]-p)) - acm;
				if (pos == n) pos--;
				int delta = m + acm[i] - abs(borders[i] - p) - acm[pos];
				if (
					((delta >= h[0] &&  delta <= h[1]) || (delta == 0))
					&&  freq[pos] - freq[i] == pos - i
				) {
					start_pnt = p;
					found = true;
				}
			}
		}
	}
	printf("%d\n", start_pnt);
}
