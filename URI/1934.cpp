#include <bits/stdc++.h>
using namespace std;
map<string, int> row[100], col[100], values;
set<string> all;
int lv[100], cv[100];
int main()
{
	int L, C, v_num = 0;
	scanf("%d %d\n", &L, &C);
	map<string, int>::iterator it;

	for (int l = 0; l < L; ++l) {
		for (int c = 0 ; c < C; ++c) {
			char buff[4];
			scanf("%s\n", buff);

			if (!row[l].count(buff)) row[l][buff] = 0;
			row[l][buff]++;

			if (!col[c].count(buff)) col[c][buff] = 0;
			col[c][buff]++;

			all.insert(buff);
		}

		scanf("%d\n", &lv[l]);

		if (row[l].size() == 1)
			values[(row[l].begin())->first] =  lv[l] / (row[l].begin())->second;
	}

	for (int c = 0; c < C; ++c) scanf("%d\n", &cv[c]);

	for (int c = 0; c < C; ++c)
		if(col[c].size() == 1)
			values[(col[c].begin())->first] = cv[c] / col[c].begin()->second;

	do {
		set<string> st;
		int count;

		for (int l = 0; l < L; ++l) {
			count = 0;
			for (it = row[l].begin(); it != row[l].end(); ++it) {
				count += values.count(it->first);
				if(!values.count(it->first)) st.insert(it->first);
			}

			if (row[l].size() - count == 1) {
				int sum = 0;

				for (it = values.begin(); it != values.end(); ++it)
					sum += row[l][it->first] * it->second;

				values[*(st.begin())] = (lv[l] - sum) / row[l][*(st.begin())];
			}
			st.clear();
		}

		for (int c = 0; c < C; ++c) {
			count = 0;
			for (it = col[c].begin(); it != col[c].end(); ++it) {
				count += values.count(it->first);
				if(!values.count(it->first)) st.insert(it->first);
			}

			if (col[c].size() - count == 1) {
				int sum = 0;

				for (it = values.begin(); it != values.end(); ++it)
					sum += col[c][it->first] * it->second;

				values[*(st.begin())] = (cv[c] - sum) / col[c][*(st.begin())];
			}
			st.clear();
		}
	} while (values.size() != all.size());

	for (it = values.begin(); it != values.end(); ++it)
		printf("%s %d\n", it->first.c_str(), it->second);
}
