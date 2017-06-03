#include <bits/stdc++.h>
using namespace std;
#define MAX 10010
int main()
{
    int n, m, i;
    set<int> checker;
    scanf("%d %d\n", &n, &m);


    for (i = 0; i < m; ++i) {
        int k;
        scanf("%d\n", &k);
        
        checker.clear();

        for (int j = 0; j < k; ++j) {
            int tmp;
            scanf("%d\n", &tmp);    
            checker.insert(tmp);
        }

        bool ok = false;

        for (set<int>::iterator it = checker.begin(); it != checker.end(); ++it)
            if (*it >= 0 && checker.count(-*it)) ok = true;

        if (!ok) break;
    }

    printf("%s\n", i != m ? "YES" : "NO");
}
