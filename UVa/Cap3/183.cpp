#include <cstdio>
#define MAX 210
char input[MAX * MAX], bitmap[MAX * MAX];
int  L, C;

int ones(int x1, int y1, int x2, int y2)
{
        int c = 0;

        for (int i = x1; i <= x2; ++i)
                for (int j = y1; j <= y2; ++j)
                        if (input[i * C + j] == '1')
                                c++;
        return c;
}

void BtoD (int x1, int y1, int x2, int y2, int &p)
{
        if (x1 > x2 || y1 > y2) return;

        int decide = ones(x1, y1, x2, y2);

        if (!decide || decide == (x2 - x1 + 1) * (y2 - y1 + 1))
                bitmap[p++] = !decide ? '0' : '1';
        else {
                bitmap[p++] = 'D';
                int midx = (x1 + x2) / 2, midy = (y1 + y2) / 2;
                BtoD(x1, y1, midx, midy, p);
                BtoD(x1, midy + 1, midx, y2, p);
                BtoD(midx + 1, y1, x2, midy, p);
                BtoD(midx + 1, midy + 1, x2, y2, p);
        }
}

void DtoB(int x1, int y1, int x2, int y2)
{
        if (x1 > x2 || y1 > y2) return;

        char tmp; scanf("%c\n", &tmp);

        if (tmp != 'D') {
                for (int i = x1; i <= x2; ++i)
                        for (int j = y1; j <= y2; ++j)
                                bitmap[i * C + j] = tmp;
        } else {
                int midx = (x1 + x2) / 2, midy = (y1 + y2) / 2;
                DtoB(x1, y1, midx, midy);
                DtoB(x1, midy + 1, midx, y2);
                DtoB(midx + 1, y1, x2, midy);
                DtoB(midx + 1, midy + 1, x2, y2);
        }
}

int main()
{
        char type;

        while (scanf("%c\n", &type) && (type != '#')) {
                scanf("%d %d\n", &L, &C);
                int Lim;

                printf("%c%4d%4d\n", type == 'B' ? 'D' : 'B', L, C);

                if (L * C > 0) {
                        if (type == 'B') {
                                for (int i = 0; i < L * C; ++i)
                                        scanf("%c\n", &input[i]);

                                int p = 0;
                                BtoD(0, 0, L - 1, C - 1, p);
                                Lim = p;
                        } else {
                                DtoB(0, 0, L - 1, C - 1);
                                Lim = L * C;
                        }

                        for (int i = 0; i < Lim; ++i) {
                                printf("%c", bitmap[i]);
                                if (!((i + 1)%50) && i + 1 != Lim) printf("\n");
                        }
                }
                printf("\n");
        }

}
