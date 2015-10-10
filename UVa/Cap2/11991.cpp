#include <cstdio>
#include <vector>
#include <utility>
#define MAX 1000001
using namespace std;

vector< int > ocurr[MAX];

int main()
{
    int n, m;
    
    while( scanf("%d %d", &n, &m) != EOF ) {
        int location = 1,
            memo     = 0;
        
        while(n--) {
            int tmp;
            
            scanf("%d", &tmp);
            ocurr[tmp].push_back( location );
            location++;
            
            if(tmp > memo)
                memo = tmp;
        }
        
        while(m--) {
            int k, v;
            
            scanf("%d %d", &k, &v);
            
            if(!ocurr[v].empty() && k <= ocurr[v].size())
                printf("%d\n", ocurr[v][k - 1]);
            else
                printf("0\n");
        }
        
        for(int i = 1; i <= memo; ++i)
            ocurr[i].clear();
    }
}