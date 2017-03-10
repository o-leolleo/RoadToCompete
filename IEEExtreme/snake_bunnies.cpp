#include <bits/stdc++.h>
using namespace std;
char grid[110][110];
int head[30], tail[30], ear[20], foot[20], pos[20], M, N;

bool is_busy(int p)
{
	int busy = 0;
	for (busy = 0; busy < M; ++busy)
		if (busy != p && pos[busy] == pos[p]) break;
	return busy != M;
}

int main()
{
	scanf("%d\n", &N);

	memset(head, -1, sizeof head);
	memset(tail, -1, sizeof tail);
	memset(ear,  -1, sizeof ear);
	memset(foot, -1, sizeof foot);
	memset(pos,  -1, sizeof pos);

	for (int l = 0; l < N; ++l) scanf("%s\n", grid[N - l - 1]);

	for (int l = 1; l < N; l += 2)
		reverse(grid[l], grid[l] + N);

	for (int l = 0; l < N; ++l)
		for (int  c = 0; c < N; ++c) {
			if (isdigit(grid[l][c])) {
				if (foot[grid[l][c] - '0'] < 0) {
					foot[grid[l][c] - '0'] = l * N + c;
				} else {
					ear[grid[l][c] - '0'] = l * N + c;
				}
			} else if (isalpha(grid[l][c])) {
				if (tail[grid[l][c] - 'a'] < 0) {
					tail[grid[l][c] - 'a'] = l * N + c;
				} else {
					head[grid[l][c] - 'a'] = l * N + c;
				}
			}
		}

	scanf("%d\n", &M);
	int p = 0, die; bool type = false;

	while (scanf("%d\n", &die) != EOF) {
		int memo = -1;
		pos[p] += die;
		memo = die;

		if (!type){
			if (scanf("%d\n", &die) != EOF) {
				pos[p] += die;
				if (memo == die) memo = -1;
			}
		}

		int loop_c = 0;

		do {
			int old = pos[p];

			if (is_busy(p)) pos[p]++;

			int x = pos[p]/N, y = pos[p]%N;

			if (isdigit(grid[x][y]) && foot[grid[x][y] - '0'] == pos[p]) {
				pos[p] = ear[grid[x][y] - '0'];
			} else if (isalpha(grid[x][y]) && head[grid[x][y] - 'a'] == pos[p]) {
				pos[p] = tail[grid[x][y] - 'a'];
			}

			if (pos[p] <= old) loop_c++;

			if (loop_c >= 2) {
				printf("PLAYER %d WINS BY EVIL CYCLE!\n", p + 1);
				exit(0);
			}
		} while (p < N * N && is_busy(p));

		if (pos[p] >= N * N) {
			pos[p] = N * N - 1;
		}

		if (!type && memo < 0) {
			type = true;
		} else {
			p = (p + 1) % M;
			type = false;
		}
	}

	printf("%d", pos[0] + 1);
	for (int p = 1; p < M; ++p)
		printf(" %d", pos[p] + 1);
	printf("\n");
}
