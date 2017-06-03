#include <bits/stdc++.h>
using namespace std;

int key(char c)
{
	if (c == 'A') return 0;
	if (c == 'C') return 1;
	if (c == 'G') return 2;
	if (c == 'T') return 3;
	return 4;
}

char _key(int i)
{
	if (i == 0) return 'A';
	if (i == 1) return 'C';
	if (i == 2) return 'G';
	return 'T';
}

bool is_equal(int *x, int *cont)
{
	for(int k = 1; k < 4;++k)
		if( cont[k] + x[k] != cont[k-1] + x[k-1])
			return false;

	return true;
}

void print(int *x, int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", x[i]);
	printf("<\n");
}

int main()
{
	int n, cont[6];
	char genome[500];

	scanf("%d\n", &n);
	scanf("%s\n",genome);
	memset(cont,0,sizeof cont);

	for (int i = 0; i < n; ++i)
		cont[key(genome[i])]++;

	int phi = cont[4], x[4];
	bool found = false;

	for (x[0] = 0; !found && x[0] <= phi; ++x[0])
		for (x[1] = x[0]; !found && x[1] <= phi - x[0]; ++x[1])
			for (x[2] = x[1]; !found && x[2] <= phi - x[0] - x[1]; ++x[2]) {
				x[3] = phi-x[0]-x[1]-x[2];

				int tmp[4];
				for (int i = 0; i < 4; ++i) tmp[i]=x[i];
				do {
					if (is_equal(tmp,cont)) {
						for (int i = 0; i < 4; ++i) x[i] = tmp[i];
						found = true;	
					}
				} while(!found && next_permutation(tmp, tmp + 4));
			}

	if (found) {
		for (int i = 0; i < 3; ++i) x[i]--;

		int now = 0;
		for (int i = 0; i < n; ++i) if (genome[i] == '?') {
			while(now < 4 && !x[now])
				now++;	

			genome[i] = _key(now);
			--x[now];
		}
		printf("%s\n",genome);	
	} else
		printf("===\n");
}
