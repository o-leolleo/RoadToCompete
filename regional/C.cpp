#include <bits/stdc++.h>
using namespace std;
typedef vector< vector<int> > state;
state start, finish;
map<state, int> memo;
set<state> aux;
int dl[] = {1, -1, 0, 0},
	dc[] = {0, 0, 1, -1};

bool eq(state a, state b)
{
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 4; ++j)
			if (a[i][j] != b[i][j])
				return false;

	return false;
}

void print(state v)
{
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 4; ++j)
			printf("%d%c", v[i][j], j + 1 == 4 ? '\n' : ' ');
	printf("\n");
}

int dp(state s)
{
	print(s);

	if (eq(s, finish)) return 0;
	if (memo.count(s)) return memo[s];

	int M = 999999999;

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 4; ++j)
			for (int k = 0; k < 4; ++k)
				if (i + dl[k] < 0 || i + dl[k] >= 2 || j + dc[k] < 0 || j + dc[k] >= 4)
					continue;
				else {
					state v; v = s;
					swap(v[i][j], v[i + dl[k]][j + dc[k]]);
					M = min(M, v[i][j] + v[i + dl[k]][j + dc[k]] + dp(v)); 
				}

	print(s);
	printf("%d\n", M);

	return memo[s] = M;
}

int main()
{
	start.assign(2, vector<int>());
	finish.assign(2, vector<int>());

	for (int i = 0; i < 2; ++i) {
		start[i].assign(4,0);
		finish[i].assign(4,0);
	}

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 4; ++j) {
			int tmp; scanf("%d\n", &tmp);
			start[i][j] = tmp;
		}

	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 4; ++j) {
			int tmp; scanf("%d\n", &tmp);
			finish[i][j] = tmp;
		}

	int p = dp(start);
	printf("%d\n", p);
}
