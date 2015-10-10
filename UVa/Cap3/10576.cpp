#include <cstdio>
#include <climits>
#define MONTHS 12

int s, q;

void backtrack( int a[MONTHS], int k, int sum5, int S, int *M )
{
    if(k >= 5 && sum5 >= 0)
        return;

    if(k == MONTHS) {
        if( S > *M )
            *M = S;

        return;
    }

    if(k >= 5)
        sum5 -= a[k - 5];

    a[k] = s;
    backtrack(a, k + 1, sum5 + s, S + s, M);

    a[k] = q;
    backtrack(a, k + 1, sum5 + q, S + q, M);
}

int main()
{
    int M, a[MONTHS];

    while( scanf("%d %d\n", &s, &q) != EOF ) {
        M = INT_MIN;
        q = -q;

        backtrack( a, 0, 0, 0, &M );

        if(M >= 0)
            printf("%d\n", M);
        else
            printf("Deficit\n");
    }
}
