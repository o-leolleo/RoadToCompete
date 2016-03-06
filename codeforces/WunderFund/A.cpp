#include <bits/stdc++.h>
using namespace std;
#define MAX 100010

void row_print(int n, int k)
{
	if (n / 2 == 0) {
		printf("%d", k); return;
	}

	row_print(n/2, k + 1);
	if (n % 2) printf(" %d", k); 
}

int main()
{
	int n, k,row[MAX];
	scanf("%d\n", &n);
	row_print(n, 1);	
	printf("\n");
}
