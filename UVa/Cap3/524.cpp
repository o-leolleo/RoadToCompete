#include <cstdio>
#define MAXN 16

int a[MAXN], gone, primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };

bool isPrime(int n) {
    int i;

    for(i = 0; i < 11 && (n != primes[i]); ++i);

    return i != 11;
}

void backtrack(int k, int n)
{
    if( k >= n && isPrime(a[0] + a[k - 1]) ) {
        for(int i = 0; i < n; ++i)
            printf("%d%c", a[i], i + 1 == n ? '\n' : ' ');

        return;
    } else
        for(int i = 2; i <= n; ++i ){
            if( !(gone & (1 << i)) && isPrime(i + a[k - 1]) ) {
                gone |= (1 << i);
                a[k] = i;
                backtrack(k + 1, n);
                gone &= ~(1 << i);
            }
        }
}

int main()
{
    int n, Case = 0, f = false;

    while( scanf("%d\n", &n) != EOF ) {
        gone = 2;
        a[0] = 1;

        if(f) printf("\n");

        printf("Case %d:\n", ++Case);

        backtrack(1,n);
        f = true;
    }
}
