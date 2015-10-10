#include <cstdio>
#include <vector>
#include <cstring>
#define lt(x) (x << 1)
#define rt(x) ((x << 1) + 1)
using namespace std;
vector<int> A;

class SegmentTree
{
private: vector<int> st, lazy; int N;

        void build(int p, int L, int R) {
                if (L == R) {
                        st[p] = A[L];
                } else {
                        int mid = (L + R) / 2;
                        build(lt(p), L, mid);
                        build(rt(p), mid + 1, R);
                        st[p] = st[lt(p)] + st[rt(p)];
                }
        }

        void update(int p, int L, int R, int i, int j, int type) {
                if (lazy[p] != -1) {
                        st[p] = lazy[p] == 0 ? R - L + 1 : lazy[p] == 1 ? 0 : R - L + 1 - st[p];
                        if (L != R) {
                                if (lazy[p] == 0) {
                                        lazy[lt(p)] = lazy[rt(p)] = 0;
                                } else if (lazy[p] == 1) {
                                        lazy[lt(p)] = lazy[rt(p)] = 1;
                                } else {
                                        lazy[lt(p)] = lazy[lt(p)] < 0 ? 2 : lazy[lt(p)] == 0 ? 1 : lazy[lt(p)] == 1 ? 0 : -1;
                                        lazy[rt(p)] = lazy[rt(p)] < 0 ? 2 : lazy[rt(p)] == 0 ? 1 : lazy[rt(p)] == 1 ? 0 : -1;
                                }
                        }
                        lazy[p] = -1;
                }

                if (i > R || j < L) return;
                if (L >= i && j >= R) {
                        st[p] = type == 0 ? R - L + 1 : type == 1 ? 0 : R - L + 1 - st[p];
                        if (L != R) {
                                if (type == 0) {
                                        lazy[lt(p)] = lazy[rt(p)] = 0;
                                } else if (type == 1) {
                                        lazy[lt(p)] = lazy[rt(p)] = 1;
                                } else {
                                        lazy[lt(p)] = lazy[lt(p)] < 0 ? 2 : lazy[lt(p)] == 0 ? 1 : lazy[lt(p)] == 1 ? 0 : -1;
                                        lazy[rt(p)] = lazy[rt(p)] < 0 ? 2 : lazy[rt(p)] == 0 ? 1 : lazy[rt(p)] == 1 ? 0 : -1;
                                }
                        }
                } else {
                        int mid = (L + R) / 2;
                        update(lt(p), L, mid, i, j, type);
                        update(rt(p), mid + 1, R, i, j, type);
                        st[p] = st[lt(p)] + st[rt(p)];
                }
        }

        int rsq(int p, int L, int R, int i, int j) {
                if (i > R || j < L) return 0;
                if (lazy[p] != -1) {
                        st[p] = lazy[p] == 0 ? R - L + 1 : lazy[p] == 1 ? 0 : R - L + 1 - st[p];
                        if (L != R) {
                                if (lazy[p] == 0) {
                                        lazy[lt(p)] = lazy[rt(p)] = 0;
                                } else if (lazy[p] == 1) {
                                        lazy[lt(p)] = lazy[rt(p)] = 1;
                                } else {
                                        lazy[lt(p)] = lazy[lt(p)] < 0 ? 2 : lazy[lt(p)] == 0 ? 1 : lazy[lt(p)] == 1 ? 0 : -1;
                                        lazy[rt(p)] = lazy[rt(p)] < 0 ? 2 : lazy[rt(p)] == 0 ? 1 : lazy[rt(p)] == 1 ? 0 : -1;
                                }
                        }
                        lazy[p] = -1;
                }
                if (L >= i && j >= R) return st[p];
                int mid = (L + R) / 2;
                return rsq(lt(p), L, mid, i, j) + rsq(rt(p), mid + 1, R, i, j);
        }
public:
        void init(int N) {
                this->N = N;
                st.assign(4 * N, 0);
                lazy.assign(4 * N, -1);
                build(1, 0, N - 1);
        }

        int rsq(int i, int j) {
                return rsq(1, 0, N - 1, i, j);
        }

        void update(int i, int j, int type) {
                update(1, 0, N - 1, i, j, type);
        }
};

SegmentTree pirates_count;

int main()
{
    int T;

    scanf("%d\n", &T);

    for(int k = 1; k <= T; ++k) {
        printf("Case %d:\n", k);

        int M; scanf("%d\n", &M);

        while(M--) {
            int  t;         scanf("%d\n", &t);
            char input[51]; scanf("%s\n", input);

            int N = strlen( input );

            while(t--)
                for(int i = 0; i < N; ++i)
                    A.push_back( input[i] - '0' );
        }

        pirates_count.init( A.size() );
        int Q, count = 0;
        scanf("%d\n", &Q);

        while(Q--) {
            char op; int i, j;

            scanf("%c %d %d\n", &op, &i, &j);
            if(op != 'S') {
                pirates_count.update(i, j, op == 'F' ? 0 : op == 'E' ? 1 : 2);
                // printf("%d <\n", pirates_count.rsq(i, j));
            } else
                printf("Q%d: %d\n", ++count, pirates_count.rsq(i, j));
        }

        A.clear();
    }
}
