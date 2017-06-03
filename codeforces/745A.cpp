#include <bits/stdc++.h>
using namespace std;
#define MAX 60
set<string> memo;
int main()
{
	char s[MAX];
	scanf("%s\n", s);
	int n = strlen(s), word_cnt = 1;

	memo.insert(s);

	for (int i = 0; i < n-1; ++i) {
		char tmp = s[n-1];
		for (int j = n-1; j > 0; --j) s[j] = s[j-1];
		s[0] = tmp;

		if (!memo.count(string(s))) {
			word_cnt++;
			memo.insert(string(s));
		}
	}

	printf("%d\n",word_cnt);
}
