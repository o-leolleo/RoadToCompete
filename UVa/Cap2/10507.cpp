#include <cstdio>
#include <cstring>
#define MAX 28

bool brain[MAX][MAX];
int  toInt[MAX];

int main()
{
    int N;

    while( scanf("%d\n", &N) != EOF ) {
        int  M, isAwake, isSet, elem;
        char a, b, c;

        M = isAwake = isSet = elem = 0;

        scanf("%d\n", &M);
        scanf("%c%c%c\n", &a, &b, &c);

        a -= 'A'; b -= 'A'; c -= 'A';

        isSet |= (1 << a); isAwake |= (1 << elem); toInt[a] = elem++;
        isSet |= (1 << b); isAwake |= (1 << elem); toInt[b] = elem++;
        isSet |= (1 << c); isAwake |= (1 << elem); toInt[c] = elem++;

        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                brain[i][j] = false;

        while(M--) {
            scanf("%c%c\n", &a, &b);

            a -= 'A'; b -= 'A';

            if( !( isSet & (1 << a) ) ) {
                isSet |= (1 << a);
                toInt[a] = elem++;
            }

            if( !( isSet & (1 << b) ) ) {
                isSet |= (1 << b);
                toInt[b] = elem++;
            }

            brain[ toInt[a] ][ toInt[b] ] = true;
            brain[ toInt[b] ][ toInt[a] ] = true;
        }

        int stack[MAX], top = -1, years = -1;

        do {
            years++;

            while(top >= 0)
                isAwake |= (1 << stack[top--]);

            for(int i = 0; i < N; ++i) {
                int n = 0;

                if( !( isAwake & (1 << i) ) ) {
                    for(int j = 0; j < N; ++j)
                        if(i != j && brain[i][j] && ( isAwake & (1 << j) ) )
                            n++;
                }

                if(n >= 3) {
                    stack[++top] = i;
                }
            }
        } while(top >= 0);

        if( isAwake == ( (1 << N) - 1 ) )
            printf("WAKE UP IN, %d, YEARS\n", years);
        else
            printf("THIS BRAIN NEVER WAKES UP\n");
    }
}
