#include <bits/stdc++.h>
using namespace std;

int cwh(int val)
{
	int sum = 0;
	if (val - 2 * 100 <= 0) return val/2;
	val -= 2 * 100; sum += 100;
	if (val - 3 * 9900 <= 0) return sum + val/3;
	val -= 3 * 9900; sum += 9900;
	if (val - 5 * 990000 <= 0) return sum + val/5;
	val -= 5 * 990000; sum += 990000;
	return sum + val / 7;
}

int main()
{
	int A, B;
	while (scanf("%d %d\n", &A, &B), A) {
		int lo = 1, hi = A - B, mid;
		while (lo != hi)
		{
			mid = (lo+hi)/2;
			if (cwh(B + mid) + cwh(mid) < cwh(A)) {
				lo = mid + 1;
			} else {
				hi = mid;
			}
		}
		printf("%d\n", hi);
	}
}
