#include <bits/stdc++.h>
using namespace std;
#define MAX 20
char a[MAX], b[MAX];
int  cont[10];
bool found;

void twice(int k, int N)
{
	char beg;

	if (k == N) {
		long long num = 0;

		for (int i = 0; b[i]; ++i)
			num = 10 * num + b[i] - '0';

		printf("%lld\n", num);

		found = true;
		return;
	}

	char tmp = a[k];

	a[k] = b[k] = '\0';
	beg = !strcmp(a,b) ? tmp : '9';
	a[k] = tmp;

	while (!found && beg >= '0') {

		if (!((k == 0 && beg == '0') || (k == 1 && b[k-1] == '0' && beg == '0')))
			cont[beg - '0']++;

		if (cont[beg - '0'] <= 2) {
			b[k] = beg;
			twice(k + 1, N);
		}

		if (!((k == 0 && beg == '0') || (k == 1 && b[k-1] == '0' && beg == '0')))
			cont[beg - '0']--;

		beg--;
	}
}

int main()
{
	scanf("%s\n", a);
	found = false;
	memset(cont, 0, sizeof cont);
	twice(0, strlen(a));
}
