#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 1000001
#define QN 101

struct cand
{
	char c; int i;

	bool operator<(struct cand b) {
		if (c != b.c)
			return c < b.c;
		else
			return i < b.i;
	}
};

struct cand input[MAX];

int main()
{
	int Q; char SS[QN], buffer[MAX];

	scanf("%s\n", buffer);
	scanf("%d\n", &Q);

	int N = strlen(buffer);

	for (int i = 0; i < N; ++i) {
		input[i].c = buffer[i];
		input[i].i = i;
	}

	sort(input, input + N);

	while (Q--) {
		scanf("%s\n", SS);

		struct cand tmp, *begin, *check;
		int next_index, i;

		tmp.c = SS[0];
		tmp.i = 0;

		check = begin = lower_bound(input, input + N, tmp);
		next_index = begin->i + 1;

		for (i = 1; SS[i]; ++i) {
			tmp.c = SS[i];
			tmp.i = next_index;

			check = lower_bound(input, input + N, tmp);

			if (check->c != tmp.c || check == input + N)
				break;

			next_index = check->i + 1;
		}

		if (!SS[i])
			printf("Matched %d %d\n", begin->i, check->i);
		else
			printf("Not matched\n");
	}
}
