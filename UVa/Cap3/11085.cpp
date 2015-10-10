#include <cstdio>
#include <cstdlib>
#include <climits>

int queens[8], lines, rd, ld;

void backtrack(int k, int sum, int *m)
{
    if( k == 8 ) {
        if( sum < *m )
            *m = sum;

        return;
    }

    for(int i = 1; i <= 8; ++i) {
        if( !( lines & ( 1 << i ) ) && !(rd & ( 1 << (i - k + 7) )) && !(ld & (1 << (i + k))) ) {
            lines |= (1 << i);
            rd    |= (1 << (i - k + 7));
            ld    |= (1 << (i + k));
            backtrack(k + 1, (i != queens[k]) ? sum + 1 : sum, m);
            lines &= ~(1 << i);
            rd    &= ~(1 << (i - k + 7));
            ld    &= ~(1 << (i + k));
        }
    }
}

int main()
{
    int i = 0, menor, Case = 0;

    while( scanf("%d\n", &queens[i++] ) != EOF ) {
        while(i < 8) scanf("%d\n", &queens[i++]);

        lines = rd = ld = 0;
        menor = INT_MAX;

        backtrack(0, 0, &menor);

        printf("Case %d: %d\n", ++Case, menor);
        i = 0;
    }
}
