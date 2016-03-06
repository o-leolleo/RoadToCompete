#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>

#define MAX 26
#define STR_MAX 100

using namespace std;

vector< pair<int, bool> > graph[MAX];

bool stars(char *str) 
{
    int i = 0;
    
    while(str[i] && str[i++] == '*');
    
    return !str[i];
}

void tree_walk(int node) 
{
    if( graph[node][0].second ) 
        return;
    
    graph[node][0].second = true;
    //printf("visiting > %c\n", node + 'A');
        
    for(int i = 1; i < graph[node].size(); ++i) {
      //  printf("%c -> %c\n", node + 'A',  graph[node][i].first + 'A');
        if( !graph[ graph[node][i].first ][0].second ) {
            tree_walk( graph[node][i].first );
        }
    }
}

int main()
{
    int n;
    
    scanf("%d\n", &n);
    
    while(n--) {
        char buffer[STR_MAX];
        
        while(gets(buffer) && !stars(buffer)) {
            char a, b;
            
            sscanf(buffer, "(%c,%c)", &a, &b);
           // printf("%c %c <\n", a, b);

            if( graph[a - 'A'].empty() )
                graph[a - 'A'].push_back( pair<int, bool> (-1, false) );
                
            if( graph[b - 'A'].empty() )
                graph[b - 'A'].push_back( pair<int, bool> (-1, false) );

            graph[a - 'A'].push_back( pair<int, bool> (b - 'A', false) );
            graph[b - 'A'].push_back( pair<int, bool> (a - 'A', false) );
        }
        
        gets(buffer);
        
        int i = 0;
        
        while(buffer[i]) {
            if(buffer[i] != ',')
                if( graph[ buffer[i] - 'A' ].empty() ) 
                    graph[ buffer[i] - 'A' ].push_back( pair<int, bool> (-1, false) );
            i++;
        }
        
        int  trees, acorns;
    
        trees = acorns = 0;
        
        for(i = 0; i < MAX; ++i)
            if( !graph[i].empty() ) {
                if( !graph[i][0].second ) {
                    if(graph[i].size() == 1) {
                        acorns++;
                        graph[i][0].second = true;
                    } else {
                        trees++;
                        tree_walk(i);
                        //printf("\n");
                    }
                }
            }
        
        printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
        
        for(i = 0; i < MAX; ++i)
            if( !graph[i].empty() )
                graph[i].clear();
    }
}