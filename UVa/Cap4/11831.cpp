#include <bits/stdc++.h>
char A[110][110], dir[] = {'S', 'L', 'N', 'O'};

int dy[] = { 0, 1, 0, -1},
    dx[] = { 1, 0,-1,  0};

int mod(int a, int p) {
	return a % p + (a < 0 ? p : 0);
}

int main()
{
	int N, M; char S[60000];
	while (scanf("%d %d %d\n", &N, &M, &S) && N) {
		int beg;
		for (int i = 0; i < N; ++i) {
			scanf("%s\n", A[i]);
			for (int j = 0; j < 4; ++j) {
				char *pos;
				if ((pos = strchr(A[i], dir[j])) != NULL) {
					beg = i * M + (pos - A[i]);
				}
			}
		}

                scanf("%s\n", S);
		int tam = strlen(S), x = beg/M, y = beg%M, toGo, sticks = 0;
		for (toGo = 0; toGo < 4; ++toGo) if (dir[toGo] == A[x][y]) break;
                A[x][y] = '.';

		for (int i = 0; i < tam; ++i) {
			if (S[i] == 'D') {
				toGo = mod(toGo - 1, 4);
			} else if (S[i] == 'E') {
				toGo = mod(toGo + 1, 4);
			} else if (
                           (x + dx[toGo] <  N)
                        && (x + dx[toGo] >= 0)
                        && (y + dy[toGo] <  M)
                        && (y + dy[toGo] >= 0)
                        && (A[x + dx[toGo]][y + dy[toGo]] != '#')
                        ) {
				x += dx[toGo]; y += dy[toGo];
				if (A[x][y] == '*') { sticks++; A[x][y] = '.'; }
			}
		}
		printf("%d\n", sticks);
	}
}
