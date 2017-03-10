#include <cstdio>
int fat[100];
#define MAX 100000
int main()
{
	int max = 1, N, cont = 0;
	scanf("%d\n", &N);
	fat[0] = 1;

	do {
		fat[max] = fat[max-1] * max;
	} while (fat[max++] <= N);
	max--;
	while (N) {
		while (N >= 0 && fat[max] <= N) {
			N -= fat[max];
			cont++;
		}
		max--;
	}

	printf("%d\n", cont);
}
