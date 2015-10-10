#include <cstdio>
#include <cstdlib>
#define MAX 10000

char matrix[MAX][MAX];

int main()
{
    int n;

    while( scanf("%d\n", &n) != EOF ) {

        for(int i = 0; i < n; ++i)
            gets(matrix[i]);

        int menor, maior = -1;

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(matrix[i][j] == '1') {
                    menor = 9999999;
                    for(int p = 0; p < n; ++p)
                        for(int k = 0; k < n; ++k)
                            if( (p != i || k != j) && (matrix[p][k] == '3') ) {
                                if(abs(k - j) + abs(p - i) < menor)
                                    menor = abs(k - j) + abs(p - i);
                            }

                    if(menor > maior)
                        maior = menor;
                }

        printf("%d\n", maior);
    }
}
