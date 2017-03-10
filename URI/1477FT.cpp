#include <bits/stdc++.h>
using namespace std;
#define LSOne(x) (x & (-x))
typedef vector<int> vi;

class FT
{
private: vi ft;
public:
    void init(int N) { ft.assign(N + 1, 0); }

    int rsq(int b) {
        int sum = 0;
        for (; b; b -= LSOne(b)) sum += ft[b];
        return sum;
    }

    void update(int b, int v) {
        for(;b < (int) ft.size(); b += LSOne(b)) ft[b] += v;
    }
};

class FTm
{
private: FT t1, t2;
public:
	void init (int N) {
		t1.init(N); t2.init(N);
	}

	int update(int a, int b, int v) {
		t1.update(a, v);
		t1.update(b + 1, -v);

                if (a > 1)
        		t2.update(a, (a - 1) * v),
        		t2.update(b + 1, -b * v);
	}

	int rsq(int b) {
		return t1.rsq(b) * b - t2.rsq(b);
	}

	int rsq(int a, int b) {
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
	}
};

int main()
{
	int N, M;
	FTm fen[3];

	while (scanf("%d %d\n", &N, &M) != EOF) {
		fen[0].init(N); fen[1].init(N); fen[2].init(N);
		fen[0].update(1, N, 1);

		while (M--) {
			char type; int l, r;
			scanf("%c %d %d\n", &type, &l, &r);

			if (type == 'M') {
				int a = fen[0].rsq(l, r),
				    b = fen[1].rsq(l, r),
				    c = fen[2].rsq(l, r);

				fen[0].update(l, r, c - a);
				fen[1].update(l, r, a - b);
				fen[2].update(l, r, b - c);
			} else {
				printf("%d %d %d\n",
                                        fen[0].rsq(l, r),
                                        fen[1].rsq(l, r),
                                        fen[2].rsq(l, r));
			}
		}
	}
}
