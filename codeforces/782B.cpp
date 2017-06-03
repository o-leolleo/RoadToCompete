#include <bits/stdc++.h>
using namespace std;

#define MAX 60100
#define F first
#define S second

typedef pair<int, int> ii;
ii xv[MAX];
int n;

double T(double p)
{
    double ans = -1;
    
    for (int k = 0; k < n; ++k)
        ans = max(ans, abs(p-xv[k].F)/xv[k].S);
    
    return ans;
}

int main()
{

    scanf("%d\n", &n);
    
    for (int k = 0; k < n; ++k) scanf("%d\n", &xv[k].F);
    for (int k = 0; k < n; ++k) scanf("%d\n", &xv[k].S);
    
    double hi=1E+9, lo = 0;
    
    for (int k = 0; k < 100; ++k) {
        double m1 = lo + (hi-lo)/3,
               m2 = hi - (hi-lo)/3;
        
        if (T(m1) < T(m2))
            hi = m2;
        else
            lo = m1;
    }
    
    printf("%lf\n", T((lo + hi)/2));
}
