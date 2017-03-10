#include <cstdio>
#define MAX 1001

int A[MAX], B[MAX];

int main()
{
    int T;

    scanf("%d\n", &T);

    while(T--) {
        int n, i = -1, sum = 0;

        scanf("%d\n", &n);

        while(n--) {
            scanf("%d\n", &A[++i]);

            if(i >= 1)
                for(int j = 0; j < i; ++j)
                    if(A[j] <= A[i])
                        sum++;

        }
        printf("%d\n", sum);
    }
}
