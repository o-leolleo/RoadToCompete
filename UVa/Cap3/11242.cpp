#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> front, rear;
vector<double> rates;

int main()
{
    int f, r, tmp, i, j; double buff;

    while( scanf("%d\n", &f) && f ) {
        scanf("%d\n", &r);

        while(f--) {
            scanf("%d\n", &tmp);
            front.push_back(tmp);
        }

        while(r--) {
            scanf("%d\n", &tmp);
            rear.push_back(tmp);
        }

        for(i = 0; i < front.size(); ++i)
            for(j = 0; j < rear.size(); ++j)
                rates.push_back( (double)(rear[j])/front[i]);

        sort(rates.begin(), rates.end());

        double spread = -1.0;

        for(i = 0; i < rates.size() - 1; ++i) {
            buff = rates[i + 1]/rates[i];

            if( buff > spread )
                spread = buff;
        }

        printf("%.2lf\n", spread);
        rates.clear(); front.clear(); rear.clear();
    }
}
