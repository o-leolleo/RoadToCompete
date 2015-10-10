#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;
#define LSOne(x) (x & (-x))
#define MAX 1001

class FT
{
private:
    vector< int > ft[MAX]; int L;
public:
    void init(int N, int M) {
        for(int i = 1; i <= N; ++i)
            ft[i].assign(M + 1, 0);
        L = N + 1;
    }

    int increment(int x, int y, int v) {
        for(; x < L; x += LSOne(x))
            for(int j = y; j < (int) ft[x].size(); j += LSOne(j))
                ft[x][j] += v;
    }

    int rsq(int x, int y) {
        int sum = 0;

        for(; x; x -= LSOne(x))
            for(int j = y; j; j -= LSOne(j))
                sum += ft[x][j];

        return sum;
    }

    int rsq(int x1, int y1, int x2, int y2) {
        int sum = rsq(x2, y2);

        if(x1 - 1)
            sum -= rsq(x1 - 1, y2);

        if(y1 - 1)
            sum -= rsq(x2, y1 - 1);

        if(x1 - 1 && y1- 1)
            sum += rsq(x1 - 1, y1 - 1);

        return sum;
    }
};


FT ft;
int vila[MAX][MAX];

int main()
{
    int N, M, day = 1, in[5];
    char line[21];

    scanf("%d %d\n", &N, &M);
    ft.init(N, M); fat.push_back(1); fat.push_back(1);
    memset(vila, 0, (M + 1) * (N + 1) * sizeof(int));

    while( gets(line) && line[0]) {
        int i = 0, j = 0, sum = 0;

        while(line[i]) {
            if(line[i] == ' ') {
                in[j] = sum;
                sum = 0;
                i++; j++;
            } else
                sum = 10*sum + (line[i++] - '0');
        }

        in[j++] = sum;

        if(j == 3) {
            ft.increment(in[0], in[1], in[2]);
            vila[in[0]][in[1]] += in[2];
        } else if(j == 2) {
            ft.increment(in[0], in[1], -1 * vila[in[0]][in[1]]);
            vila[in[0]][in[1]] = 0;
        } else {
            int b = ft.rsq(in[0], in[1], in[2], in[3]);
            printf("Day #%d: %d\n", day++, );
        }
    }
}
