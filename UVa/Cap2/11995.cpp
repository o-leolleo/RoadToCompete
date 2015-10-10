#include <cstdio>
#include <queue>
#include <map>
#define MAX 1001

using namespace std;

int st[MAX], qe[MAX];
priority_queue<int> prior;

int main()
{
    int n, top, first, last;
    
    while( scanf("%d", &n) != EOF ) {
        bool s, q, p;
        
        first = last = 0;
        top = -1;
        s = q = p = true;

        for(int i = 0; i < n; ++i) {
            int a1, a2;
            
            scanf("%d %d", &a1, &a2);
            
            if(a1 == 1) {
                prior.push(a2);
                st[++top]  = a2;
                qe[last++] = a2;
            } else {
                if( p ) {
                    if(prior.empty() || prior.top() != a2) 
                        p = false;
                    else 
                        prior.pop();
                }
                
                if( q ) {
                    if(first == last || qe[first] != a2) 
                        q = false;
                    else
                        first++;
                }
                    
                if( s ) {
                    if(top < 0 || st[top] != a2) 
                        s = false;
                    else
                        top--;
                }
            }
        }
        
        if( (s && q) || (s && p) ||  (q && p) )
            printf("not sure\n");
        else if( s )
            printf("stack\n");
        else if( q )
            printf("queue\n");
        else if( p )
            printf("priority queue\n");
        else
            printf("impossible\n");
            
        while( !prior.empty() )
            prior.pop();
    }
}