#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    char str[10], a[10], b[10];

    scanf("%d\n", &n);
    scanf("%s\n", str);

    while(n--) {
        int i = 0;
        do { scanf("%c\n", &a[i]);  } while (a[i]!='-');
        scanf("%c\n", &a[i]);
        scanf("%s\n", b);
    }

    if (!strcmp(b,str)) printf("home\n");
    else printf("contest\n");
}
