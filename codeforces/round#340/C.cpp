#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define mp make_pair
ii P1, P2;
vector<ii> P;

ll dist(ii a, ii b)
{
	return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}

bool comp1(ii a, ii b)
{
	return dist(P1, a) < dist(P1, b);	
}

class comp2 
{
public:	
	bool operator()(ii a, ii b)
	{
		return dist(P2, a) < dist(P2, b);
	}
};

multiset<ii, comp2> D2;

int main()
{
	int n, x1, y1, x2, y2;

	scanf("%d %d %d %d %d\n", &n, &x1, &y1, &x2, &y2);
	P1 = mp(x1,y1); P2 = mp(x2,y2);

	for (int i = 0; i < n; ++i) {
		scanf("%d %d\n", &x1, &y1);
		P.push_back(mp(x1,y1));
	}

	sort(P.begin(), P.end(), comp1);

	for (int i = 0; i < P.size(); ++i)
		D2.insert(P[i]);


	set<ii>::iterator tmp = D2.end();
	ll menor = dist(*(--tmp), P2);

	for (int i = 0; i < n; ++i) {
		ll r1 = dist(P1, P[i]), r2 = 0;	

		D2.erase(P[i]);

		if (!D2.empty()) {
			tmp = D2.end();
			r2 = dist(*(--tmp), P2);
		}
	
		menor = min(menor, r1 + r2);
	}

	printf("%lld\n", menor); 
}
