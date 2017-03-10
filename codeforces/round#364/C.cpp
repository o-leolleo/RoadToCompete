#include <bits/stdc++.h>
using namespace std;
#define MAX 10100 

int main()
{
	char flat[MAX];
	int N, mem[500];

	scanf("%d %s\n", &N, flat);
	memset(mem, 0, sizeof mem);

	int begin = 0, end = 0;

	for (int k = 0; k < N; ++k) {
		if (!mem[flat[k] - 'a']) {
			end = k;
			mem[flat[k] - 'a']++;
		} else if (flat[k] == flat[begin]) {
			end = k;
			while (begin <= end && mem[flat[begin] - 'a'] > 0)
				begin++;
		}

		if (begin > end) end = begin;
	}

	for (int k = begin; k <= end; ++k) printf("%c", flat[k]);
	printf("\n");
	printf("%d\n", end - begin + 1);	
}
