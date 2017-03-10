#include <bits/stdc++.h>
using namespace std;
int T, sdk[4][4];

int row[4], col[4], sqr[2][2];

bool backtrack(int pos)
{
	if (pos == 16) return true;

	int i = pos/4, j = pos%4;

	if (sdk[i][j]) return backtrack(pos+1);

	for (int c = 0; c < 4; ++c) {
		if (!(row[i] & (1 << c)) && !(col[j] & (1 << c)) && !(sqr[i/2][j/2] & (1 << c))) {
			row[i] |= (1 << c);
			col[j] |= (1 << c);
			sqr[i/2][j/2] |= (1 << c);
			sdk[i][j] = c + 1;

			if (backtrack(pos + 1)) return true; 
			
			row[i] &= ~(1 << c);
			col[j] &= ~(1 << c);
			sqr[i/2][j/2] &= ~(1 << c);
			sdk[i][j] = 0;
		}
	}

	return false;
}

int main()
{
	scanf("%d\n", &T);

	for (int c = 1; c <= T; ++c) {
		memset(row, 0, sizeof row);
		memset(col, 0, sizeof col);
		memset(sqr, 0, sizeof sqr);

		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j) {
				char tmp;
				scanf("%c\n", &tmp);

				if (tmp == '*')
					sdk[i][j] = 0;
				else {
					sdk[i][j] = tmp - '0';
					row[i] |= (1 << (tmp - '0' - 1));
					col[j] |= (1 << (tmp - '0' - 1));
					sqr[i/2][j/2] |= (1 << (tmp - '0' - '1'));
				}
			}
			
			backtrack(0);

			printf("Case #%d:\n", c);
			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j  < 4; ++j)
					printf("%c", sdk[i][j] ? sdk[i][j] + '0' : '*');
				printf("\n");
			}
	}
}
