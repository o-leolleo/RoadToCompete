#include <cstdio>
#include <vector>
#include <map>
#include <string>

#define MAX 100001

using namespace std;

class UnionFind
{
private:
    vector<int> p, rank, size;
    int nOfElem;
public:
    UnionFind() { nOfElem = 0; }

    void extendSet() {
        p.push_back(0); rank.push_back(0); size.push_back(1);
        p[nOfElem] = nOfElem++;
    }

    inline int  findSet  (int i) { return p[i] == i ? i : (p[i] = findSet(p[i])); }
    inline bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    inline int  sizeOfSet(int i) { return size[ findSet(i) ];  }

    void unionSet(int i, int j) {
        int x = findSet(i),
            y = findSet(j);

        if(rank[x] > rank[y]) {
            p[y] = x;
            size[x] += size[y];
        } else {
            p[x] = y;
            size[y] += size[x];

            if(rank[x] == rank[y])
                rank[y]++;
        }
    }
};

map<string, int> sToInt;

int main()
{
    int N;

    scanf("%d\n", &N);

    while(N--) {
        int F, elem = 0;

        scanf("%d\n", &F);

        char n1[21], n2[21];
        string s1, s2;
        UnionFind network;

        while(F--) {
            scanf("%s %s\n", n1, n2);

            s1.assign(n1); s2.assign(n2);

            if( !sToInt.count(s1) ) {
                sToInt[s1] = elem++;
                network.extendSet();
            }

            if( !sToInt.count(s2) ){
                sToInt[s2] = elem++;
                network.extendSet();
            }

            if( !network.isSameSet( sToInt[s1], sToInt[s2] ) )
                network.unionSet( sToInt[s1], sToInt[s2] );

            printf("%d\n", network.sizeOfSet( sToInt[s1] ));
        }

        sToInt.clear();
    }
}
