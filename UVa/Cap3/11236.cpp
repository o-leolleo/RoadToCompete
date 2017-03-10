#include <cstdio>
#define MAX 2000
#define DEN 1000000
int main()
{
    long long i, j, k, p, prod;

    for(i = 1; i <= 212; ++i)
        for(j = i; j < MAX - i; ++j)
            for(k = j; k < MAX - i - j; ++k)
                if( (i * k * j > DEN) && !( (DEN * (i + j + k)) % ( i * j * k - DEN ) ) ) {
                        p = DEN * (i + j + k) / ( i * j * k - DEN );

                        if((p >= k) && p + k + i + j <= MAX) {
                            prod = i * j * k * p;
                            if(!(prod % DEN) && (i + k + j + p) == (prod / DEN) )
                                printf("%d.%02d %d.%02d %d.%02d %d.%02d\n", i/100, i%100, j/100, j%100, k/100, k%100, p/100, p%100);
                        }
                }
}
