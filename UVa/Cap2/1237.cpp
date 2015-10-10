#include <cstdio>
#include <cstring>
#define MAX 10001
typedef struct maker { char name[22]; int L, H; } maker;

maker db[MAX];

int main()
{
	int T, D, L, H, Q, P;
	char M[22];

	scanf("%d\n", &T);

	while(T--) {
		scanf("%d\n", &D);

		int i = 0;

		while(D--) {
			scanf("%s %d %d\n", M, &L, &H);

			strcpy(db[i].name, M);
			db[i].L = L;
			db[i].H = H;
			i++;
		}

		scanf("%d\n", &Q);

		while(Q--) {
			scanf("%d\n", &P);

			int count = 0, maker;

			for(int k = 0; k < i; k++)
				if(db[k].L <= P && P <= db[k].H) {
					count++;

					if(count == 1)
						maker = k;
				}

			if(count == 1)
				printf("%s\n", db[maker].name);
			else
				printf("UNDETERMINED\n");
		}

		if(T) printf("\n");
	}
}
