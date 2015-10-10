#include <cstdio>
#include <vector>

using namespace std;

class UnionFind 
{
private:
    vector<int> p, rank;    
public:
    UnionFind(int N) {
        p.assign(N, 0);
        rank.assign(N, 0);
        
        for(int i = 0; i < N; ++i) 
            p[i] = i;
    }
    
    int findSet(int i) { return p[i] == i? i : ( p[i] = findSet(p[i]) ); }
    
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    
    void unionSet(int i, int j) {
        int x = findSet(i), y = findSet(j);
        
        if(rank[x] > rank[y]) 
            p[y] = x;
        else {
            p[x] = y;
            
            if(rank[x] == rank[y])
                rank[y]++;
        }
    }
};

int main()
{
    int n;
    
    scanf("%d", &n);
    getchar();
    
    while(n--) {
        int comp, success, unsuccess;
        
        scanf("%d\n", &comp);
        
        UnionFind network(comp);
        char buffer[10];
        
        success = unsuccess = 0;
        
        while( gets(buffer) && buffer[0] ) {
            char mod; int ci, cj;
            
            sscanf(buffer,"%c %d %d\n", &mod, &ci, &cj);
            ci--; cj--;
            
            if(mod == 'c')
                network.unionSet(ci, cj);
            else {
                if( network.isSameSet(ci, cj) )
                    success++;
                else
                    unsuccess++;
            }
        }
        
        printf("%d,%d\n", success, unsuccess);
        
        if(n) 
            printf("\n");
    }
}