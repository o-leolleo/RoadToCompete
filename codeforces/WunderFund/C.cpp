#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
#define EPS 1E-9
typedef long long ll;
typedef pair<ll, ll> ii;
#define mp make_pair
ii ref;

ll dist(ii a, ii b)
{
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second); 
}

double angle(ii a, ii b)
{
	return (double)(a.first * b.first  + a.second * b.second) / sqrt(sqrt(dist(a, ii(0,0))) * sqrt(dist(b, ii(0,0))));
}

class Comp
{

public:
	bool operator()(ii a, ii b) const
	{
		double t1 = angle(a, ref), t2 = angle(b, ref);
		if (fabs(t1 - t2) < EPS) return dist(a, ref) < dist(b, ref); 
		return t1 < t2;
	}
};

map<ii, int, Comp> star;

int main()
{
	int n, order = 1;
	scanf("%d\n", &n);

	ll x, y;
	scanf("%lld %lld\n", &x, &y);
	ref = mp(x,y);

	for (int i = 1; i < n; ++i) {
		scanf("%lld %lld\n", &x, &y);
		star[ii(x, y)] = ++order; 
		printf("%d\n", star.size());
	}

	map<ii, int, Comp>::iterator it = star.begin();
	int i = 0;

	printf("1");

	while (i < 2) {
		printf(" %d", it->second);
		it++;
		i++;
	}

	printf("\n");
}
