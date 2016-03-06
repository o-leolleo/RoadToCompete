#include <cstdio>
#include <vector>
using namespace std;
#define LSOne(x) (x & (-x))

class FenwickTree
{
private: vector<int> ft;
public:
    void assign(int N) { ft.assign(N + 1, 0); }

    int rsq(int b) {
        int sum = 0;
        for(; b; b -= LSOne(b)) sum += ft[b];
        return sum;
    }

    int rsq(int a, int b) {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }

    void increment(int b, int v) {
        for(;b < (int) ft.size(); b += LSOne(b)) ft[b] += v;
    }

    void clear() {
        ft.clear();
    }
};

vector<int> V;
FenwickTree zeroes, negatives;

int main()
{
    int N, K, tmp, a, b; char op;

    while( scanf("%d %d\n", &N, &K) != EOF ) {
        V.push_back(0);
        zeroes.assign(N); negatives.assign(N);

        for(int i = 1; i <= N; ++i) {
            scanf("%d\n", &tmp);
            V.push_back(tmp);

            if (!tmp)
                zeroes.increment(i, 1);
            else if(tmp < 0)
                negatives.increment(i, 1);
        }

        while(K--) {
            scanf("%c %d %d\n", &op, &a, &b);

            if(op == 'C') {
                if(!V[a] && b)
                    zeroes.increment(a, -1);
                else if(V[a] && !b)
                    zeroes.increment(a,  1);

                if(V[a] < 0 && b >= 0)
                    negatives.increment(a, -1);
                else if (V[a] >= 0 && b < 0)
                    negatives.increment(a,  1);

                V[a] = b;
            } else {
                if(zeroes.rsq(a, b) > 0) printf("0");
                else if( negatives.rsq(a, b) % 2 ) printf("-");
                else printf("+");
            }
        }

        printf("\n");
        zeroes.clear();
        negatives.clear();
        V.clear();
    }
}
