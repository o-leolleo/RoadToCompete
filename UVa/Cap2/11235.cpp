#include <cstdio>
#include <vector>

using namespace std;

class SegmentTree
{
private:
    vector<int> st, A;
    int N;

    int left(int p) { return p << 1; }
    int right(int p) { return (p << 1)  + 1; }

    void build(int p, int L, int R) {
        if(L == R)
            st[p] = L;
        else {
            build( left(p), L, (L + R) / 2 );
            build( right(p), (L + R) / 2 + 1, R);

            int p1 = st[ left(p) ], p2 = st[ right(p) ];

            st[p] = ( A[p1] >= A[p2] ) ? p1 : p2;
        }
    }

    int rmq(int p, int L, int R, int i, int j) {
        if( i >  R || j <  L ) return -1;
        if( L >= i && R <= j ) return  st[p];

        int p1 = rmq( left(p) , L            , (R+L) / 2, i, j ),
            p2 = rmq( right(p), (R+L) / 2 + 1, R        , i, j );

        if( p1 == -1 ) return p2;
        if( p2 == -1 ) return p1;

        return (A[p1] >= A[p2]) ? p1 : p2;
    }

public:
    SegmentTree(const vector<int> &_A) {
        A = _A; N = (int) _A.size();
        st.assign(4 * N, 0);
        build(1, 0, N - 1);
    }

    int rmq(int i, int j) { return rmq( 1, 0, N - 1, i, j ); }
};

int main()
{
    int  n, q, case_count = 0;
    vector<int> A, B, F;

    while( scanf("%d\n", &n) && n ) {
        scanf("%d\n", &q);

        int old, count = 1;

        scanf("%d\n", &old); n--;
        B.push_back(old);

        while(n--) {
            int tmp;

            scanf("%d\n", &tmp);
            B.push_back(tmp);

            if(old != tmp) {
                F.push_back(count);
                old = tmp;
                count = 0;
            }

            count++;
        }

        F.push_back(count);

        int j = 0;
        count = 0;

        while( j < F.size() ) {
            A.push_back( F[j] );
            count++;

            if( count == F[j] ) {
                count = 0;
                j++;
            }
        }

        SegmentTree frequencies( A );

        while(q--) {
            int a, b, lim_1, lim_2, f;

            lim_1 = lim_2 = f = -1;

            scanf("%d %d\n", &a, &b);
            a--; b--;

            if( a > 0 && B[a - 1] == B[a] )
                for( lim_1 = a; lim_1 < b && B[ lim_1 ] == B[ lim_1 + 1 ]; ++lim_1 );

            if( b + 1 < B.size() && B[b] == B[b + 1])
                for( lim_2 = b; lim_2 > a && B[lim_2 - 1] == B[lim_2]; --lim_2 );

            if( lim_1 != b && lim_2 != a) {
                if(lim_1 != -1 && lim_2 != -1) {
                    f = max( lim_1 - a + 1, b - lim_2 + 1 );
                    a = lim_1 + 1;
                    b = lim_2 - 1;
                } else if(lim_1 != -1) {
                    f = lim_1 - a + 1;
                    a = lim_1 + 1;
                } else if(lim_2 != -1) {
                    f = b - lim_2 + 1;
                    b = lim_2 - 1;
                }

                if(a <= b)
                    f = max(f, A[ frequencies.rmq(a, b) ]);
            } else
                f = b - a + 1;

            printf("%d\n", f);
        }

        A.clear(); F.clear(); B.clear();
    }
}
