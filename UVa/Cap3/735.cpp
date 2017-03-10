#include <cstdio>
#define TAM 43

int main()
{
    int n, perm, comb;
    int v[] = {
                0, 1, 2, 3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24,
                26, 27, 28, 30, 32, 33, 34, 36, 38, 39, 40, 42, 45, 48, 50, 51, 54, 57, 60
            };

    while( scanf("%d\n", &n) && (n > 0) ) {
        perm = comb = 0;

        if(n <= 180) {
            for(int i = 0; i < TAM && v[i] <= n; ++i)
                for(int j = 0; j < TAM && v[j] <= n - v[i]; ++j)
                    for(int k = 0; k < TAM && v[k] <= n - v[i] - v[j]; ++k)
                        if( v[i] + v[j] + v[k] == n ) {
                            if(i <= j && j <= k) comb++;
                            perm++;
                        }
        }

        if(comb) {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, comb);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, perm);
        } else
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);

        for(int i = 0; i < 70; ++i) printf("*");
        printf("\n");
    }

    printf("END OF OUTPUT\n");
}
