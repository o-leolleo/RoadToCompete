#include <bits/stdc++.h>
using namespace std;
bool isPrime(int N) {
	int lim = (int) sqrt(N);
	if (N % 2 == 0) return false;
	for (int i = 3; i <= lim; i+=2)
		if (N % i == 0) return false;
	return true;
}
int main()
{
	int N;

	while (scanf("%d\n", &N) != EOF) {
		if (isPrime(N)) {
			int memo, tmp = 0; memo = N;
			while (N) {
				tmp = 10 * tmp + N % 10;
				N /= 10;
			}
			if (isPrime(tmp) && tmp != memo)
				printf("%d is emirp.\n", memo);
			else
				printf("%d is prime.\n", memo);
		} else
			printf("%d is not prime.\n", N);
	}
}
