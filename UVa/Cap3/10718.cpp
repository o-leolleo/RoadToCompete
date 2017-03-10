#include <cstdio>

int main()
{
        unsigned int N, L, U;

        while (scanf("%u %u %u\n", &N, &L, &U) != EOF) {
                if (L == U)
                        printf("%u\n", L);
                else {
                        unsigned int M = 0;

                        for (int i = 31; i >= 0; --i)
                                if ((!(N & (1 << i)) && (M | (1 << i)) <= U) || ((N & (1 << i)) && (M < L) && (L & (1 << i))))
                                        M |= (1 << i);

                        printf("%u\n", M);
                }
        }
}
