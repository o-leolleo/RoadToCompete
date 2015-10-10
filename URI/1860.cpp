#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> ii;
#define MAX 50010
ii P[MAX];

double dist(ii a, ii b)
{
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}



int main()
{
	int N, X, big;
	double D = -1.;

	scanf("%d %d\n", &N, &X);

	for (int i = 0; i < N; ++i) {
		int a, b;

		scanf("%d %d\n", &a, &b);

		P[i].first  = a;
		P[i].second = b;

		D = max(D, dist(ii(0., 0.), P[i]));
	}

	double hi, lo, mid = 0.;

	hi = X;
	lo = 0.;

	while (fabs(hi - lo) > 1e-9) {
		mid = (hi + lo) / 2.;

		D = -1.;

		for (int i = 0; i < N; ++i) {
			double tmp = dist(ii(mid, 0.), P[i]);

			if (tmp > D) {
				D   = tmp;
				big = i;
			}
		}

		if (P[big].first > mid)
			lo = mid;
		else
			hi = mid;
	}

	printf("%.2lf %.2lf\n", mid, D);
}
