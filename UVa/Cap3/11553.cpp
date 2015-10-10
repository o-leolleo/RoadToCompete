#include <cstdio>
#include <algorithm>
#define MAX 9
using namespace std;

/*
    -- NAO ENTENDI DE FORMA ALGUMA POR QUE ESSE CÓDIGO FUNCIONA --
                    DON'T ASK ME.
*/

int grid[MAX][MAX], V[MAX];

int main()
{
    int t, n, lines, columns;

    scanf("%d\n", &t);

    while(t--) {
        scanf("%d\n", &n);

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d\n", &grid[i][j]);

        for(int i = 0; i < n; ++i)
            V[i] = i;

        int columns, M = 99999;

        do {
            int sum;
            sum = columns = 0;

            for(int i = 0; i < n; ++i) {
                int menor = 99999, cc;

                for(int j = 0; j < n; ++j)
                    if( !(columns & (1 << j)) && grid[ V[i] ][j] < menor ) {
                        menor = grid[ V[i] ][j];
                        cc    = j;
                    }

                sum += grid[ V[i] ][ cc ];
                columns |= (1 << cc);
            }

            if(sum < M)
                M = sum;

        } while( next_permutation(V, V + n) );

        printf("%d\n", M);
    }
}
