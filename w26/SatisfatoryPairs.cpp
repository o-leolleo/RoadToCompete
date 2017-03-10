#include<bits/stdc++.h>
using namespace std;

vector<int> mult;
vector<int> g_prime_list;
vector<bool> is_prime;

int x, y, d;

void extendedEuclid(int a, int b) {
	if(b == 0) { x = 1; y = 0; d = a; return; }

	extendedEuclid(b, a%b);

	int x1 = y,
		y1 = x - (a / b) * y;

	x = x1;
	y = y1;
}

int gcd(int a, int b) { return b ? gcd(b,a%b):a;}

void sieve(int n)
{
	int k = 2;

	is_prime.assign(n, true);
	g_prime_list.clear();
	g_prime_list.push_back(1);
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

int main()
{
	int n;
	scanf("%d\n", &n);

	sieve(n);

	for (int i = 1; i <= sqrt(n); ++i)
		if (n%i==0) mult.push_back(i);

	mult.push_back(n);
	int cont = 0;

	for (int k = 0; k < mult.size(); ++k) {
		for (int i = 1; i < n; ++i)
			for (int j = i + 1; j < n; ++j) if (gcd(j,i)==1) {
					int a = mult[k] * i,
						b = mult[k] * j;

					extendedEuclid(b, a);

					int y0 = x * n / d,
						x0 = y * n / d;

					double tmp1 = -(double)(x0)*d/b,
						   tmp2 = (double)(y0)*d/a;

					int pota1 = floor(tmp1),
						pota2 = ceil(tmp2);

					if (pota1 + 2 <= pota2) {
						cont++;
					}
				}
	}

	printf("%d\n", cont);
}
