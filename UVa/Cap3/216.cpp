#include <bits/stdc++.h>
using namespace std;
numeric_limits<double> DOUBLE;
double dist[10][10], dp[10][600];
int coord[10][2], V;

double TSP (int pos, int bitmask)
{
	if (bitmask == (1 << V) - 1) return 0;
	double &ans = dp[pos][bitmask];
	if (ans != -1.) return ans;
	ans = DOUBLE.max();
	for (int nxt = 0; nxt < V; ++nxt)
		if (nxt != pos && !(bitmask & (1 << nxt)))
			ans = min(ans, dist[pos][nxt] + TSP(nxt, bitmask | (1 << nxt)));
	return ans;

}

void print_path(int pos, int bitmask)
{
	if (bitmask == (1 << V) - 1) return;
	for (int nxt = 0; nxt < V; ++nxt)
		if (nxt != pos && !(bitmask & (1 << nxt)) && dp[pos][bitmask] == dist[pos][nxt] + TSP(nxt, bitmask | (1 << nxt))) {
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",
			coord[pos][0], coord[pos][1],
			coord[nxt][0], coord[nxt][1],
			dist[pos][nxt]);
			print_path(nxt, bitmask | (1 << nxt));
		}
}

int main()
{
	int network = 0; bool f = false;
	printf("**********************************************************\n");
	while (scanf("%d\n", &V), V) {
		if (f) printf("**********************************************************\n");
		for (int i = 0; i < V; ++i) scanf("%d %d\n", &coord[i][0], &coord[i][1]);

		for (int a = 0; a < V; ++a)
			for (int b = a + 1; b < V; ++b)
				dist[a][b] = dist[b][a] = sqrt(
					(coord[a][0] - coord[b][0]) * (coord[a][0] - coord[b][0])
				+	(coord[a][1] - coord[b][1]) * (coord[a][1] - coord[b][1])
				) + 16.;

		for (int a = 0; a < 10; ++a) for (int b = 0; b < 600; ++b)
			dp[a][b] = -1.;

		int bs = 0; double ans = DOUBLE.max();

		for (int v = 0; v < V; ++v)
			if (TSP(v, 0 | (1 << v)) < ans) {
				ans = TSP(v, 0 | (1 << v));
				bs = v;
			}

		printf("Network #%d\n", ++network);
		TSP(bs, 0 | (1 << bs)); print_path(bs, 0 | (1 << bs));
		printf("Number of feet of cable required is %.2lf.\n", TSP(bs, 0 | (1 << bs)));
		f = true;
	}
}
