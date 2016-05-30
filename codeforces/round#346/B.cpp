#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
	vector< multimap<int, string> > region;
	vector<int> qt_region;

	scanf("%d %d\n", &n, &m);

	region.assign(n, multimap<int, string>());
	qt_region.assign(n, 0);

	for (int i = 0; i < n; ++i) {
		char aux[20];
		int reg, score;

		scanf("%s %d %d\n", aux, &reg, &score); 
		qt_region[reg-1]++;

		region[reg-1].insert(make_pair(~score, string(aux)));
	}

	for (int i = 0; i < m; ++i) {
		int comp = region[i].begin()->first;

		if (region[i].count(comp) > 2) {
			printf("?\n"); continue;
		}

		multimap<int,string>::iterator it = region[i].begin();

		while (it->first == comp) it++;

		if (region[i].count(comp) == 1 && region[i].count(it->first) > 1) {
			printf("?\n");
			continue;
		}
		
		else printf("%s %s\n", region[i].begin()->second.c_str(), (++(region[i].begin()))->second.c_str());
	}
}
