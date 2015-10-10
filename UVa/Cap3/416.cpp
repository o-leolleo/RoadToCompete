#include <cstdio>

char led[10][8], map[10][8] = {
        "YYYYYYN",
        "NYYNNNN",
        "YYNYYNY",
        "YYYYNNY",
        "NYYNNYY",
        "YNYYNYY",
        "YNYYYYY",
        "YYYNNNN",
        "YYYYYYY",
        "YYYYNYY"
};

int  a[10], burn;
bool found;

void backtrack(int k, int i, int N)
{
        if (k >= N)
                found = true;
        else {
                for (int j = 0; j < 7; ++j)
                        if ((burn & (1 << j)) && led[i][j] == 'Y')
                                return;

                for (int j = 0; j < 10; ++j) {
                        int p, toBurn = 0;

                        for (p = 0; p < 7; ++p)
                                if (map[j][p] == 'N' && led[i][p] == 'Y')
                                        break;
                                else if (map[j][p] == 'Y' && led[i][p] == 'N')
                                        toBurn |= (1 << p);

                        if ((p == 7) && (k > 0 ? (a[k - 1] == j + 1) : 1)) {
                                a[k] = j;
                                burn |= toBurn;
                                backtrack(k + 1, i + 1, N);
                                burn &= ~toBurn;
                        }
                }
        }
}

int main()
{
        int N;

        while ((scanf("%d\n", &N) != EOF) && N) {
                for (int i = 0; i < N; ++i)
                        scanf("%s\n", led[i]);

                burn  = 0;
                found = false;
                backtrack(0, 0, N);

                printf("%s\n", found ? "MATCH" : "MISMATCH");
        }
}
