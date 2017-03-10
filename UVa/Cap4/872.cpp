#include <bits/stdc++.h>
using namespace std;
#define MAX 50
int dat[MAX], rdat[MAX], DAG[MAX], p[MAX], tam;
char str[5*MAX]; bool flag = false;

void bk_dfs(int k, int mask)
{
	if (k == tam) {
		str[k] = '\0';
		flag = true;
		for (int i = 0; i < tam; ++i)
			printf("%c%c", str[i], i + 1 == tam ? '\n' : ' ');
		return;
	}

	for (int a = 0; a < tam; ++a)
		if (!(mask & (1 << a)) && (mask & p[a]) == p[a]) {
			str[k] = (char) (rdat[a] + 'A');
			bk_dfs(k + 1, mask | (1 << a));
		}
}

int main()
{
	int T;
	scanf("%d\n", &T);

	while (T--) {
		memset(DAG, 0, sizeof DAG);
		memset(p, 0, sizeof p);

		char in[100];
		int N = strlen(gets(in)), aux = 0;

		for (int i = 0; i < N; ++i)
			if (in[i] != ' ')
				in[aux++] = in[i];

		in[aux] = '\0';
		tam = N = strlen(in);
		sort(in, in + N);
		aux = 0;

		for (int i = 0; i < N; ++i) if(in[i] != ' ')
			dat[in[i] - 'A'] = aux,
			rdat[aux++] = in[i] - 'A';

		N = strlen(gets(in));
		getchar();

		for (int i = 0; i < N; ++i)
			if (in[i] != ' ') {
				int a, b;
				a = in[i] - 'A';
				i+=2;
				b = in[i] - 'A';
				DAG[dat[a]] |= (1 << dat[b]);
				p[dat[b]] |= (1 << dat[a]);
			}

		bk_dfs(0, 0);

		if (!flag) printf("NO\n");
		if (T) printf("\n");
		flag = false;
	}
}
