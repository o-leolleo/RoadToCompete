#include <cstdio>
#define MAX 14
int lotto[MAX];

int main()
{
    int k, n; bool flag = true;

    while( scanf("%d\n", &k) && k ) {
        n = 0;

        if(!flag) printf("\n");

        while(k--) scanf("%d\n", &lotto[n++]);

        for(int i = 0; i < n - 5; ++i)
            for(int j = i + 1; j < n - 4; ++j)
                for(int k = j + 1; k < n - 3; ++k)
                    for(int p = k + 1; p < n - 2; ++p)
                        for(int q = p + 1; q < n - 1; ++q)
                            for(int m = q + 1; m < n; ++m)
                                printf("%d %d %d %d %d %d\n", lotto[i], lotto[j], lotto[k], lotto[p], lotto[q], lotto[m]);

        flag = false;
    }
}
