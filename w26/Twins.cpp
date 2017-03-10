#include <bits/stdc++.h>
using namespace std;
vector<bool> is_prime;
vector<int> g_prime_list;

void sieve(int n)
{
	int k = 2;

	is_prime.assign(n, true);
	g_prime_list.clear();
	is_prime[0] = is_prime[1] = false;

	while(k <= n) {
		if (is_prime[k]) {
			for (int i = 2*k; i <= n; i += k) if (is_prime[i])
				is_prime[i] = false;

			g_prime_list.push_back(k);
		}
		k++;
	}
}

bool isPrime(int n)
{
	int k, lim = sqrt(n);

	if (n < is_prime.size())
		return is_prime[n];

	k = 0;

	while (k < g_prime_list.size() && g_prime_list[k] < lim) {
		if (n % g_prime_list[k] == 0) return false;
		k++;
	}

	return true;
}

int main()
{
	int n, m;
	vector<int> prime_list;
	
	scanf("%d %d\n", &n, &m);

	if (m < 1e+7) sieve(m);
	else sieve(100000);

	for (int num = n; num <= m; ++num)
		if (isPrime(num))
			prime_list.push_back(num);

	int pair_count = 0;

	for (int i = 1; i < prime_list.size(); ++i)
		if (abs(prime_list[i]-prime_list[i-1]) == 2)
			pair_count++;

	printf("%d\n", pair_count);
}
