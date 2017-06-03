#include <bits/stdc++.h>
using namespace std;
#define MAX 100100
typedef long long ll;

ll A[MAX], time_end[MAX];
ll ts, tf, t, ans, m;
int n;

ll delay(int i) { return time_end[i-1] - A[i] + 1 > 0 ? time_end[i-1] - A[i] + 1 : 0; }

int main()
{
    scanf("%lld %lld %lld %d\n", &ts, &tf, &t, &n);

    A[0] = 0;
    time_end[0] = ts;

    for (int i = 1; i <= n; ++i) {
        scanf("%lld\n", &A[i]); 
        time_end[i] = time_end[i-1] > A[i] ? time_end[i-1] + t : A[i] + t;
    }

    A[n+1] = time_end[n] + 1;

    m = numeric_limits<ll>::max();
    ll ans = -1, the_end = ts;

    for (int i = 1; i <= n + 1; ++i) {
        while (A[i] == A[i-1]) ++i;

        ll D = delay(i),
           arrival = !D ? time_end[i-1] : A[i] - 1;

        if (arrival <= tf - t && D < m) {
            m = D;
            ans = arrival;
        }
    }

    printf("%lld\n", ans);
}
