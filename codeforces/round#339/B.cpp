#include <bits/stdc++.h>
using namespace std;
#define MAX 100010

int main()
{
	int N, sum = 0; 
	char nonb[MAX];
	bool x = false;

	scanf("%d\n", &N);
	strcpy(nonb, "1");

	while (N--) {
		char buff[MAX];
		scanf("%s\n", buff);
		int tam = strlen(buff);
		int i = 0, cont = 0;

		while (buff[i] && cont < 2 && (buff[i] == '0' || buff[i] == '1')) i++, cont += (int) (buff[i-1] == '1');

		if (buff[i] || cont >= 2) strcpy(nonb, buff);
		else sum += tam - 1;

		if (tam == 1 && buff[0] == '0') x = true;
	}

	if (x) printf("0\n");
	else {
		printf("%s", nonb);
		for (int i = 0; i < sum; ++i) printf("0");
		printf("\n");
	}
}
