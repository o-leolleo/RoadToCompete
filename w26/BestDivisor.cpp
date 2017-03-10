#include <bits/stdc++.h>
using namespace std;

int sum(int n)
{
	int s = 0;

	while (n) {
		s += n%10;
		n /= 10;
	}

	return s;
}

bool tosort(int a, int b) 
{
	if (sum(a) > sum(b))
		return true;
	if (sum(a) < sum(b))
		return false;
	else
		return a < b;
}

int main()
{
	int n;
	vector<int> divisors;

	scanf("%d\n", &n);

	for (int div = 1; div <= n; ++div)
		if (!(n%div)) divisors.push_back(div);

	sort(divisors.begin(), divisors.end(), tosort);
	printf("%d\n", divisors[0]);
}
