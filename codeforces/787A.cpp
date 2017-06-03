#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d;
    bool found = false;
    
    scanf("%d %d %d %d\n", &a, &b, &c, &d);
    
    if (d > b) {
        swap(d,b);
        swap(a,c);
    }
    
    for (int i = 0; i <= 100; ++i)
        if ((b - d + i * a) % c == 0) {
            printf("%d\n", b + i * a);
            found = true;
            break;
        }

    if (!found)
        printf("-1\n");
}
