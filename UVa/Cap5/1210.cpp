#include <bits/stdc++.h>
using namespace std;
bitset<10010> bs;
int prime[10010], tam;

int bt(int n, int val)
{
	if (n > tam) return 0;
	int ans = 0;
	for (int id = 0; id < tam - n; ++id)
		if (prime[id + n - 1] - (id > 0 ? prime[id - 1] : 0) == val)
			ans++;
	return ans + bt(n + 1, val);
}

int main()
{
	int N; bs.set();
	bs[0] = bs[1] = 0; tam = 0;

	for (int i = 2; i <= 10000; ++i) if (bs[i]) {
		for (int j = i * i; j <= 10000; j += i)
			bs[j] = 0;
		prime[tam] = i;
		if (tam > 0) prime[tam] += prime[tam - 1];
		tam++;
	}

	while (scanf("%d\n", &N) && N)
		printf("%d\n", bt(1, N));
}
