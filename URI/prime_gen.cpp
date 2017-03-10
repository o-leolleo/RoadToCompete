#include <bits/stdc++.h>
using namespace std;

int main()
{
	for (int i = 2; i <= 1000000000; ++i) {
		int j;

		for (j = 2; j <= (int) sqrt(i); ++j)
			if (!(i % j)) break;

		if (j > (int) sqrt(i)) printf("%d\n", i);
	}
}
