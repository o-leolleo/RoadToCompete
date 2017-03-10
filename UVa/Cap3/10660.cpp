#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define MAX 5

typedef struct Area { int x, y, c; } Area;
Area city[MAX * MAX];

int main()
{
    int t, n, x, y, c, area, tam;

    scanf("%d\n", &t);

    while(t--) {
        scanf("%d\n", &n);
        tam = 0;

        while(n--) {
            scanf("%d %d %d\n", &x, &y, &c);
            city[tam].x = x;
            city[tam].y = y;
            city[tam].c = c;
            tam++;
        }

        int area = 0, choosen, global_min = 999999, sum;

        for(int off1 = 0; off1 < MAX * MAX - 4; area = 0, ++off1) {
            area |= (1 << off1);

            for(int off2 = off1 + 1; off2 < MAX * MAX - 3; area &= ~(1 << off2), ++off2) {
                area |= (1 << off2);

                for(int off3 = off2 + 1; off3 < MAX * MAX - 2; area &= ~(1 << off3), ++off3) {
                    area |= (1 << off3);

                    for(int off4 = off3 + 1; off4 < MAX * MAX - 1; area &= ~(1 << off4), ++off4) {
                        area |= (1 << off4);

                        for(int off5 = off4 + 1; off5 < MAX * MAX   ; area &= ~(1 << off5), ++off5) {
                            sum = 0;
                            area |= (1 << off5);

                            for(int i = 0; i < tam; ++i) {
                                int local_min = 999999;

                                for(int bit = 0; bit < MAX * MAX; ++bit)
                                    if(area & (1 << bit)) {
                                        int measure = city[i].c * ( abs( city[i].x - bit/5 ) + abs( city[i].y - bit%5) );

                                        if(measure < local_min)
                                            local_min = measure;
                                    }

                                sum += local_min;
                            }

                            if(sum < global_min) {
                                global_min = sum;
                                choosen    = area;
                            }
                        }
                    }
                }
            }
        }

        bool f = false;

        for(int b = 0; b < 25; ++b) {
            if( choosen & (1 << b) ) {
                if(f) printf(" ");
                printf("%d", b);
                f = true;
            }
        }

        printf("\n");
    }
}
