#include <cstdio>
#include <vector>
#include <utility>

#define MAX 10000
using namespace std;

vector< pair<int, int> > matrix[MAX], 
                         transpose[MAX];

int main()
{
    int m, n;

    while( scanf("%d %d", &m, &n) != EOF ) {
        for(int k = 0; k < m; ++k) {
            int r;

            scanf("%d", &r);

            for(int i = 0; i < r; ++i) {
                int tmp;

                scanf("%d", &tmp);
          //      printf("%d ", tmp);
                matrix[k].push_back( pair<int, int> (0, tmp) );
            }
            
         //   printf("\n");

            for(int i = 0; i < r; ++i) {
                int tmp;

                scanf("%d", &tmp);
           //     printf("%d ", tmp);
                matrix[k][i].first = tmp;
            }

           // printf("\n");
            getchar();
        }

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < matrix[i].size(); ++j)
                transpose[ matrix[i][j].second - 1 ].push_back( pair<int, int> ( matrix[i][j].first, i + 1) );
        }
        
        printf("%d %d\n", n, m);
        
        for(int i = 0; i < n; ++i) {
            printf("%lu", transpose[i].size());
            
            for(int j = 0; j < transpose[i].size(); ++j) {
                printf(" %d", transpose[i][j].second);
            }
            
            printf("\n");
            
            for(int j = 0; j < transpose[i].size(); ++j) {
                if(j) printf(" ");
                printf("%d", transpose[i][j].first);
            }
            
            printf("\n");
        }
        
        for(int i = 0; i < m; ++i)
            if( !matrix[i].empty() )
                matrix[i].clear();
        
        
        for(int i = 0; i < n; ++i)
            if( !transpose[i].empty() )
                transpose[i].clear();
    }
}
