#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, d = 0, nd = 0;

    scanf("%d %d\n", &n, &k);
    
    if (n==0)
        printf("0\n");
    else {
        while (k && n % (int)(pow(10,k))) {
            if (n % 10) d++;
            else k--;
            n /= 10;
            nd++;
        }
        
        printf("%d\n", n ? d : nd - 1);
    }
}
