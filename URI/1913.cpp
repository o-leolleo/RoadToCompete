#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>
#include <map>
#include <algorithm>
using namespace std;

bool can(int c1, int c2)
{
        return !((c1 == 1 && c2 == 2) || (c1 == 2 && c2 == 4) || (c1 == 4 && c2 == 3) || (c1 == 3 && c2 == 1));
}

typedef struct Cilindro {
        int h, r, cor;

        bool operator <(const struct Cilindro &b) const {
                return r < b.r;
        }
} Cilindro;

#define MAX 10010

Cilindro mesa[MAX];
map<string, int> trans;
Cilindro LIS[MAX];

int main()
{
        int N;

        trans["VERMELHO"] = 1;
        trans["LARANJA"]  = 2;
        trans["VERDE"]    = 3;
        trans["AZUL"]     = 4;

        while (scanf("%d\n", &N) && N) {
                for (int i = 0; i < N; ++i) {
                        char buff[35];
                        scanf("%d %d %s\n", &mesa[i].h, &mesa[i].r, buff);
                        int tam = strlen(buff);

                        for (int j = 0; j < tam; j++)
                                buff[j] = toupper(buff[j]);

                        mesa[i].cor = trans[buff];
                }

                memset(LIS, 0, sizeof LIS);
                sort(mesa, mesa + N);

                LIS[0] = mesa[0];

                int tam = 0, ans = mesa[0].h;

                for (int i = 1; i < N; ++i) {
                        if (can(LIS[tam].cor, mesa[i].cor)) {
                                if (LIS[tam].r == mesa[i].r && LIS[tam].h >= mesa[i].h)
                                        continue;

                                if (LIS[tam].r != mesa[i].r) tam++;

                                LIS[tam] = mesa[i];
                                LIS[tam].h += LIS[tam - 1].h;
                                ans = max(ans, LIS[tam].h);
                        } else
                                ans = max(ans, mesa[i].h);
                }

                printf("%d centimetro(s)\n", ans);
        }
}
