#include <cstdio>
#include <bitset>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int lcm(int a, int b) {
        if (a < b) {
                int tmp = a;
                a = b;
                b = tmp;
        }

        return a * (b / gcd(a, b));
}

bitset<100100> foi;

int main()
{
        int N, T;

        while (scanf("%d %d\n", &N, &T) && N) {
                int old; scanf("%d\n", &old);

                foi.reset(); foi.set(old);

                for (int i = 1; i < N; ++i) {
                        int tmp;
                        scanf("%d\n", &tmp);

                        old = lcm(tmp, old);
                        foi.set(tmp);
                }

                if (T % old) printf("impossivel\n");
                else {
                        int i;

                        for (i = 2; i <= T; ++i)
                                if (!foi[i] && lcm(i, old) == T) break;

                        if (i == T + 1) printf("impossivel\n");
                        else printf("%d\n", i);
                }
        }
}
