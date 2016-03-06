#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
    int T;

    srand(time(NULL));

    T = rand()%100 + 1;
    printf("%d\n", T);

    while(T--) {
        int M;

        M = rand()%100 + 1;
        printf("%d\n", M);

        int sum = 0;

        while(M--) {
            int t; t = rand()%200 + 1;
            int N; N = rand()%50 + 1;

            printf("%d\n", t);

            int input[50];

            for(int i = 0; i < N; ++i)
                input[i] = rand()%2;

            for(int i = 0; i < N; ++i)
                printf("%d", input[i]);
            printf("\n");

            sum += N*t;
        }

        int Q; Q = rand()%1000 + 1;
        printf("%d\n", Q);

        while(Q--) {
            int choice; choice = rand()%4;
            int i, j;
            char c;

            i = rand()%(sum) + 1;
            j = rand()%(sum) + sum;

            if(choice == 0) c = 'F';
            else if(choice == 1) c = 'E';
            else if(choice == 2) c = 'I';
            else if(choice == 3) c = 'S';

            printf("%c %d %d\n", c, i, j);
        }
    }
}
