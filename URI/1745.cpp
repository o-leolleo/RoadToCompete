#include <bits/stdc++.h>
using namespace std;
#define LEN 1000100
queue<int> q;
typedef long long ll;

ll process(int *buffer, int N)
{
	ll cont = 0, total = 0;

	for (int k = 0; k < N; ++k) {
		if (buffer[k] && (q.empty() || (q.front()+buffer[k])%3))
			q.push(buffer[k]);
		else {
			if (buffer[k]) {
				cont = 1;
				q.pop();
			} else
				cont++;

			total += cont;
		}
	}

	return total;
}

int main()
{
	char str[LEN];
	int N, buffer[LEN], tam;
	ll total;

	scanf("%s\n", str);
	N = strlen(str);
	total = tam = 0;

	for (int k = 0; k < N; ++k)
		if (isdigit(str[k]))
			buffer[tam++] = (str[k]-'0')%3;
		else if (tam) {
		 	total += process(buffer, tam);
			tam = 0;
		}

	if (tam) total += process(buffer, tam);

	printf("%lld\n", total);
}
