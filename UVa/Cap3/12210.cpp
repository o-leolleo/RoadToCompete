#include <cstdio>
#define MAX 10010
int b[MAX];

int main()
{
        int B, S, caso = 1;

        while (scanf("%d %d\n", &B, &S) && B) {
                int menor = 999999;
                for (int i = 0; i < B; ++i) {
                        scanf("%d\n", &b[i]);
                        if(b[i] < menor)
                                menor = b[i];
                }

                for (int i = 0; i < S; ++i) {
                        int tmp;
                        scanf("%d\n", &tmp);
                }

                printf("Case %d: %d", caso++, B - S > 0 ? B - S : 0);
                if (B - S > 0) printf(" %d", menor);
                printf("\n");
        }
}
