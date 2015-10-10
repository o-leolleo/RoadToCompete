#include <bits/stdc++.h>
using namespace std;
typedef pair <long long, long long> ii;
typedef vector<long long> vi;
typedef vector<ii> vii;
vii sk;
vi LIS, LDS;
int main()
{
	int N, T;
	scanf("%d\n", &T);

	for (int caso = 1; caso <= T; ++caso) {
		scanf("%d\n", &N);
		sk.assign(N + 1, ii());

		for (int i = 0; i < N; ++i) {
			long long tmp;
			scanf("%lld\n", &tmp);
			sk[i].first = tmp;
		}

		for (int i = 0; i < N; ++i) {
			long long tmp;
			scanf("%lld\n", &tmp);
			sk[i].second = tmp;
		}

		long long max1, max2; max1 = max2 = -1;

		for (int i = 0; i < N; ++i) {
			LIS.push_back(sk[i].second);
			LDS.push_back(sk[i].second);

			for (int j = 0; j < i; ++j) {
				if (sk[j].first < sk[i].first)
					LIS[i] = max(LIS[i], LIS[j] + sk[i].second);
				else if (sk[j].first > sk[i].first)
					LDS[i] = max(LDS[i], LDS[j] + sk[i].second);
			}

			max1 = max(max1, LIS[i]);
			max2 = max(max2, LDS[i]);
		}

		printf("Case %d. %s (%lld). %s (%lld).\n",
			caso,
			max1 >= max2 ? "Increasing" : "Decreasing",
			max1 >= max2 ? max1 : max2,
			max1 >= max2 ? "Decreasing" : "Increasing",
			max1 >= max2 ? max2 : max1
		);

		LIS.clear(); LDS.clear();
	}
}
