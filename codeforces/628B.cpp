#include <bits/stdc++.h>
using namespace std;
#define MAX 400000
int main()
{
	char str[MAX];
	scanf("%s\n", str);
	
	int n = strlen(str);
	long long cont = 0;
	str[n] = '3'; str[n+1] = '\0';
	
	for (int k = 0; k < n; ++k) {
		if (((str[k] - '0') * 10 + (str[k+1] - '0')) % 4 == 0)
			cont += k + 1;
		
		if ((str[k] - '0') % 4 == 0)
			cont++;
	}	
	printf("%lld\n", cont);
}