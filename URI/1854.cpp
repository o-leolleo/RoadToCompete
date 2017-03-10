#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define LSOne(x) (x & (-x))
#define P 1000000007
typedef long long ll;

class FT
{
private:  vector<vi> ft;
        int rsq(int x, int y) {
                int sum = 0;
                for (; x; x -= LSOne(x))
                        for (int k = y; k; k -= LSOne(k))
                                sum += ft[x][k];
                return sum;
        }
public:
        void init(int N, int M) {
                ft.assign(N + 1, vi());
                for (int a = 1; a <= N; ++a)
                        ft[a].assign(M + 1, 0);
        }

        void increment(int a, int b, int v) {
                for (;a < (int) ft.size(); a += LSOne(a))
                        for (int k = b; k < (int) ft[a].size(); k += LSOne(k))
                                ft[a][k] += v;
        }

        int rsq(int a, int b, int c, int d) {
                int sum = rsq(c, d);
                if (a - 1 > 0) sum -= rsq(a - 1, d);
                if (b - 1 > 0) sum -= rsq(c, b - 1);
                if (a - 1 > 0 && b - 1 > 0) sum += rsq(a - 1, b - 1);
                return sum;
        }
};

ll degree(ll a, ll k)
{
        ll res = 1;
        while (k) {
                if (k % 2 == 1) res = (res * a) % P;
                k /= 2;
                a = (a * a) % P;
        }
        return res;
}

ll binom(ll N, ll K)
{
        ll res = 1;
        if (K > N - K) K = N - K;
        for (ll i = 0; i < K; ++i)
                res = (res * (N - i)) % P;
        ll denom = 1;
        for (ll i = 2; i <= K; ++i)
                denom = (denom * i) % P;
        return (res * degree(denom, P - 2)) % P;
}

int main()
{
        int N, M, winterfell[1010][1010], day = 0;
        FT boneco; char buff[1000];
        scanf("%d %d\n", &N, &M);
        boneco.init(N, M);
        memset(winterfell, 0, sizeof winterfell);

        while (gets(buff) != NULL) {
                int v[6], tam = 0;
                v[0] = 0;

                for (int a = 0; buff[a]; ++a) {
                        if (buff[a] == ' ') {
                                tam++;
                                v[tam] = 0;
                        } else
                                v[tam] = 10 * v[tam] + (buff[a] - '0');
                }

                tam++;

                if (tam == 3) {
                        boneco.increment(v[0], v[1], v[2]);
                        winterfell[v[0]][v[1]] += v[2];
                } else if (tam == 2) {
                        boneco.increment(v[0], v[1], -1 * winterfell[v[0]][v[1]]);
                        winterfell[v[0]][v[1]] = 0;
                } else {
                        int b = boneco.rsq(v[0], v[1], v[2], v[3]);
                        printf("Day #%d: %lld\n", ++day, b == 0 ? 0 : binom(v[4] + b - 1, b - 1));
                }
        }
}
