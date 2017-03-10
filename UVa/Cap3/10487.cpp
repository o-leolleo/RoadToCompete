#include <cstdio>
#include <cstdlib>
#define MAX 1001
#define UPPER 1000000000
int v[MAX];

int main()
{
    int n, m, tmp, i, Case = 1;

    while( scanf("%d\n", &n) && n ) {
        printf("Case %d:\n", Case++);

        i = 0;

        while(n--)
            scanf("%d\n", &v[i++]);

        scanf("%d\n", &m);

        while(m--) {
            scanf("%d\n", &tmp);
            int menor = UPPER;

            for(int k = 0; k < i; ++k)
                for(int p = 0; p < i; ++p)
                    if(p != k && ( abs(v[p] + v[k] - tmp) < abs(menor - tmp) ) )
                        menor = v[p] + v[k];

            printf("Closest sum to %d is %d.\n", tmp, menor);
        }
    }
}
