#include <bits/stdc++.h>
using namespace std;
#define lt(p) (p << 1)
#define rt(p) ((p << 1) + 1)
vector<int> A;

class ST
{
private: vector<int> st[3], lazy; int N;
	void build(int p, int L, int R) {
		if (L == R)
			for (int i = 0; i < 3; ++i) st[i][p] = (A[L] % 3 == i) ? 1 : 0;
		else {
			int mid = (L + R) / 2;
			build(lt(p), L, mid);
			build(rt(p), mid + 1, R);

			for (int i = 0; i < 3; ++i)
				st[i][p] = st[i][lt(p)] + st[i][rt(p)];
		}
	}

	int rsq(int p, int L, int R, int i, int j) {
		if (i > R || j < L) return 0;
		update(p, L, R);
		if (i <= L && R <= j) return st[0][p];
		int mid = (L + R) / 2;
		return rsq(lt(p), L, mid, i, j)
		+ rsq(rt(p), mid + 1, R, i, j);
	}

	void update(int p, int L, int R) {
		if (lazy[p] != 0) {
			for (int i = 0; i < lazy[p]; ++i) {
				int a = st[0][p], b = st[1][p], c = st[2][p];
				st[0][p] = c;
				st[1][p] = a;
				st[2][p] = b;
			}

			if (L != R) {
				lazy[lt(p)] = (lazy[lt(p)] + lazy[p]) % 3;
				lazy[rt(p)] = (lazy[rt(p)] + lazy[p]) % 3;
			}
			lazy[p] = 0;
		}
	}

	void sum1(int p, int L, int R, int i, int j) {
		update(p, L, R);

		if (i > R || j < L) return;

		if (L >= i && R <= j) {
			int a = st[0][p],
			    b = st[1][p],
			    c = st[2][p];

			st[0][p] = c;
    			st[1][p] = a;
    			st[2][p] = b;

			if (L != R) {
				lazy[lt(p)] = (lazy[lt(p)] + 1) % 3;
				lazy[rt(p)] = (lazy[rt(p)] + 1) % 3;
			}
		} else {
			int mid = (L + R) / 2;
			sum1(lt(p), L, mid, i, j);
			sum1(rt(p), mid + 1, R, i, j);

			for (int i = 0; i < 3; ++i)
				st[i][p] = st[i][lt(p)] + st[i][rt(p)];
		}
	}
public:
	void init(int N) {
		for (int i = 0; i < 3; ++i) st[i].assign(4 * N, 0);
		lazy.assign(4 * N, 0);
		this->N = N; build(1, 0, N - 1);
	}

	int rsq(int i, int j)   { return rsq(1, 0, N - 1, i, j); }
	void sum1(int i, int j) { sum1(1, 0, N - 1, i, j); }

};

ST three_count;

int main()
{
	int N, Q;
	scanf("%d %d\n", &N, &Q);
	A.assign(N + 1, 0);
	three_count.init(N);

	while (Q--) {
		int t, a, b;
		scanf("%d %d %d\n", &t, &a, &b);

		if (t) printf("%d\n", three_count.rsq(a, b));
		else three_count.sum1(a, b);
	}
}
