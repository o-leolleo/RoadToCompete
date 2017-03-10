#include <cstdio>
#include <cmath>
#define MAX 21
int bars[MAX];

int main()
{
    int t, n, p;

    scanf("%d\n", &t);

    while(t--) {
        scanf("%d %d\n", &n, &p);

        for(int i = 0; i < p; ++i)
            scanf("%d\n", &bars[i]);

        int  N  = pow(2, p) - 1;
        bool ok = false;

        for(int i = 0; i <= N; ++i) {
            int sum = 0;

            for(int j = 0; j < p; ++j)
                if( i & (1 << j) )
                    sum += bars[j];

            if(sum == n) {
                printf("YES\n");
                ok = true;
                break;
            }
        }

        if(!ok) printf("NO\n");
    }
}
