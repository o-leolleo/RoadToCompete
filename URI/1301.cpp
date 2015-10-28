#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define LSOne(b) (b & (-b))

class FT
{
private: vi ft;
public:
	void init(int N) {
		ft.assign(N + 1, 0);
	}

	void increment(int k, int v) {
		for (; k <= (int) ft.size(); k += LSOne(k)) ft[k] += v;
	}

	int rsq(int b) {
		int sum = 0;
		for (; b; b -= LSOne(b)) sum += ft[b];
		return sum;
	}

	int rsq(int a, int b) {
		return rsq(b) - (a - 1 == 0 ? 0 : rsq(a - 1));
	}
};

int main()
{
	int N, K;
	FT cont[2];

	while (scanf("%d %d\n", &N, &K) != EOF) {
		cont[0].init(N); cont[1].init(N);

		for (int i = 1; i <= N; ++i) {
			int tmp; scanf("%d\n", &tmp);
			if (tmp == 0) cont[0].increment(i, 1);
			else if (tmp < 0) cont[1].increment(i, 1);
		}

		for (int c = 0; c < K; ++c) {
			char type; int k, v;
			scanf("%c %d %d\n", &type, &k, &v);

			if (type == 'C') {
				if (v > 0) {
					cont[0].increment(k, -1 * cont[0].rsq(k,k));
					cont[1].increment(k, -1 * cont[1].rsq(k,k));
				} else if (v == 0) {
					if (cont[0].rsq(k,k) == 0) cont[0].increment(k, 1);
				} else {
					if (cont[1].rsq(k,k) == 0) cont[1].increment(k, 1);
				}
			} else {
				if (cont[0].rsq(k, v) != 0) printf("0");
				else if (cont[1].rsq(k, v) % 2 == 0) printf("+");
				else printf("-");
			}
		}

		printf("\n");
	}
}
