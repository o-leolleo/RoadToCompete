#include <cstdio>
#include <cstdlib>
#define MAX 20

int tracks[MAX], memo[MAX + 1];

void backtrack(int a[], int k, int p, int n, int sum, int desired, int *M, int *S)
{
    if(k > n || sum > desired) return;

    if(desired - sum < *M) {
        *M = desired - sum;
        *S = sum;

        int i;

        for(i = 0; i < k; ++i)
            memo[i] = a[i];

        memo[i] = -1;
    }

    for(int i = p; i < n; ++i) {
        a[k] = i;
        backtrack(a, k + 1, i + 1, n, sum + tracks[i], desired, M, S);
    }
}

int main()
{
    int N, T, menor, sum, a[MAX];

    while( scanf("%d\n", &N)  != EOF ) {
        scanf("%d\n", &T);

        for(int i = 0; i < T; ++i)
            scanf("%d\n", &tracks[i]);

        menor = 99999; sum = 0;

        backtrack(a, 0, 0, T, 0, N, &menor, &sum);

        for(int i = 0; memo[i] >= 0; ++i)
            printf("%d ", tracks[ memo[i] ]);

        printf("sum:%d\n", sum);
    }
}
