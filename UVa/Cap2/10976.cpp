#include <cstdio>
#include <vector>
using namespace std;
vector<int> nums[2];

int main()
{
    int k, x, y;

    while( scanf("%d\n", &k) != EOF ) {
        y = k;

        do {
            y++;
            x = -1;

            if( !( (k * y) % (y - k) ) ) {
                x = (k * y) / (y - k);

                if( k * (x + y) == (x * y) ) {
                    nums[0].push_back(x);
                    nums[1].push_back(y);
                }
            }
        } while( x != y );

        printf("%d\n", nums[0].size());

        for(int i = 0; i < nums[0].size(); ++i)
            printf("1/%d = 1/%d + 1/%d\n", k, nums[0][i], nums[1][i]);

        nums[0].clear();
        nums[1].clear();
    }
}
