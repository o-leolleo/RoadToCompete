#include <cstdio>

int main()
{
    int N, A, B, C;

    scanf("%d\n", &N);

    while(N--) {
        scanf("%d %d %d\n", &A, &B, &C);
        bool f = false;

        for(int x = -22; x <= 22; ++x)
            for(int y = x + 1; y <= A - x; ++y)
                if(y > x) {
                    int z = A - x - y;

                    if(z > x && z > y && (x * y * z == B) && (x * x + y * y + z * z == C)) {
                        printf("%d %d %d\n", x, y, z); f = true;
                    }
                }

        if(!f) printf("No solution.\n");
    }
}
