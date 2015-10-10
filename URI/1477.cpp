#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
private: vector<int> st[3], lazy;
	 int N;

	 int lt(int p) {return (p << 1); }
	 int rt(int p) {return (p << 1) + 1;}

	 void build(int p, int L, int R) {
		 if (L == R) {
			 st[0][p] = 1;
		 } else {
			 int mid = (L + R) / 2;
			 build(lt(p), L, mid);
			 build(rt(p), mid + 1, R);
			 st[0][p] = st[0][lt(p)] + st[0][rt(p)];
		 }
	 }

	 void change(int p, int L, int R, int i, int j) {
		 if (lazy[p] != 0) {
		 	lazy[p] %= 3;
			for (int i = 1; i <= lazy[p]; ++i) {
		 		int a = st[0][p],
		 		    b = st[1][p],
		 		    c = st[2][p];

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

		 if (i > R || j < L) return;

		 if (L >= i && R <= j) {
			 int a = st[0][p],
			     b = st[1][p],
			     c = st[2][p];

			 st[0][p] = c;
			 st[1][p] = a;
			 st[2][p] = b;

			 if (L != R) {
				 lazy[lt(p)]++;
				 lazy[rt(p)]++;
			 }
			 return;
		 }

		 int mid = (L + R) / 2;
		 change(lt(p), L, mid, i, j);
		 change(rt(p), mid + 1, R, i, j);
		 st[0][p] = st[0][lt(p)] + st[0][rt(p)];
		 st[1][p] = st[1][lt(p)] + st[1][rt(p)];
		 st[2][p] = st[2][lt(p)] + st[2][rt(p)];
	 }

	 int rsq(int p, int L, int R, int i, int j, int value) {
		 if (i > R || j < L) return 0;

		 if (lazy[p] != 0) {
			lazy[p] %= 3;
			for (int i = 1; i <= lazy[p]; ++i) {
				int a = st[0][p],
				    b = st[1][p],
				    c = st[2][p];

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

		 if (L >= i && R <= j)
			 return st[value][p];

		 int mid = (L + R) / 2;

		 return   rsq(lt(p), L, mid, i, j, value)
		 	+ rsq(rt(p), mid + 1, R, i, j, value);
	 }
public:
	void init(int n) {
		N = n;
		lazy.assign(4 * N, 0);
		st[0].assign(4 * N, 0); // count zeroes
		st[1].assign(4 * N, 0); // count ones
		st[2].assign(4 * N, 0); // count twos
		build(1, 0, N - 1);
	}

	int rsq(int i, int j, int value) { return rsq(1, 0, N - 1, i, j, value);}
	void change(int i, int j) { change(1, 0, N - 1, i, j); }
};

int main()
{
	int N, M;
	SegmentTree motherfucker;

	while (scanf("%d %d\n", &N, &M) != EOF) {
		char type; int l, r;

		motherfucker.init(N);

		while (M--) {
			scanf("%c %d %d\n", &type, &l, &r);
			l--; r--;
			if (type == 'M') {
				motherfucker.change(l, r);
			} else {
				printf("%d %d %d\n",
					motherfucker.rsq(l, r, 0),
					motherfucker.rsq(l, r, 1),
					motherfucker.rsq(l, r, 2));
			}
		}
		printf("\n");
	}
}
