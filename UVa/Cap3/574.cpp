#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define MAXN 12

int list[MAXN];
vector<int> memo;

bool repeat( int a[], int k)
{
    for(int i = 0; i < memo.size(); ++i) {
        int count = 0, store = 0;

        for(int j = 0; j < k; ++j) {
            int b;

            for(b = 0; b < MAXN ; ++b)
                if( !(store & (1 << b)) && ( memo[i] & (1 << b) ) && ( list[b] == list[ a[j] ] ) ) {
                    store |= (1 << b);
                    break;
                }

            if(b != MAXN) count++;
        }

        if(count == k)
            return true;
    }

    return false;
}

void backtrack( int a[], int k, int begin, int sum, int t, int n )
{
    if( sum > t ) return;

    if(k > 0 && sum == t) {
        if( !repeat(a, k) ) {
            memo.push_back(0);

            for(int i = 0; i < k; ++i) {
                memo[ memo.size() - 1 ] |= (1 << a[i]);
                printf("%d%c", list[ a[i] ], i + 1 == k ? '\n' : '+');
            }
        }
        return;
    }

    for(int i = begin; i < n; ++i) {
        a[k] = i;
        backtrack(a, k + 1, i + 1, sum + list[i], t, n);
    }
}

int main()
{
    int n, t, a[MAXN];

    while( scanf("%d %d\n", &t, &n) && n ) {
        for(int i = 0; i < n; ++i)
            scanf("%d\n", &list[i]);

        printf("Sums of %d:\n", t);
        backtrack(a, 0, 0, 0, t, n);

        if( memo.empty() )
            printf("NONE\n");

        memo.clear();
    }
}
