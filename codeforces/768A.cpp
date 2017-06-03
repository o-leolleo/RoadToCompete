#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

int main()
{
    int stw[MAX], n;

    scanf("%d\n", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d\n", &stw[i]);

    sort(stw, stw + n);

    int f = 0, b = n-1;
    while (f < n-1 && stw[f]==stw[f+1]) f++; 
    while (b >= 1 && stw[b-1]==stw[b])  b--;
    b--;
    if (f < b) printf("%d\n", b-f);
    else printf("0\n");
}
