#include <bits/stdc++.h>
using namespace std;
#define MAX 200010

typedef long long ll;

int main()
{
	char a[MAX], b[MAX];

	scanf("%s %s\n", a, b);

	int ta = strlen(a), tb = strlen(b);
	ll ones[MAX], sum = 0;

	ones[0] = b[0] - '0';

	for (int i = 1; i < tb; ++i)
		ones[i] = b[i] - '0' + ones[i - 1];

	for (int i = 0; i < ta; ++i)
		if (a[i] == '0')
			sum += ones[i + (tb - ta)] - (i > 0 ? ones[i - 1] : 0);
		else
			sum += (tb - ta + 1) - (ones[i + (tb - ta)] - (i > 0 ? ones[i - 1] : 0));

	printf("%lld\n", sum);
}
