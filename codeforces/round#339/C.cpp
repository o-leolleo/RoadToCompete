#include <bits/stdc++.h>
using namespace std;

typedef struct point { 
	double x, y; 
	point() {x = y = 0.0;}
	point(double _x, double _y) : x(_x), y(_y) {}
} point;

typedef struct vec {
	double x, y;
	vec() { x = y = 0.0; }
	vec(double _x, double _y) : x(_x), y(_y) {}
} vec;

vec toVec(point a, point b) { return vec(b.x - a.x, b.y - a.y); }
vec scale(vec v, double s) { return vec(v.x * s, v.y * s); }
point translate(point p, vec v) { return point(p.x + v.x, p.y + v.y); }
double dist(point a, point b) { return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }
double dot(vec u, vec v) { return u.x * v.x + u.y * v.y; }	
double norm_sq(vec u) {	return u.x * u.x + u.y * u.y; }

double distToLine(point a, point b, point p)
{
	vec ap = toVec(a,p), ab = toVec(a,b);
	double u = dot(ap, ab) / norm_sq(ab);
	a = translate(a, scale(ab, u));
	return dist(a, p);
}

double distToSeg(point a, point b, point p)
{
	vec ap = toVec(a,p), ab = toVec(a,b);
	double u = dot(ap,ab) / norm_sq(ab);
	if (u < 0.0) return dist(p, a);
	if (u > 1.0) return dist(p, b);
	return distToLine(a, b, p);
}

vector<point> P;

int main()
{
	int N, x, y, mx, my, Mx, My;
	double D, d;

	scanf("%d %d %d\n", &N, &x, &y);
	D = -1.0;

	while (N--) {
		int a, b;
		scanf("%d %d\n", &a, &b);
		double dis; 
		dis = dist(point(a,b), point(x,y));
		P.push_back(point(a, b));

		if (dis > D) {
			D = dis;
			Mx = a;
			My = b;
		}
	}

	d = 1E+16;

	for (int i = 0; i < P.size(); ++i) {
		if (distToSeg(P[i], P[(i+1) % P.size()], point(x, y)) < d)
			d = distToSeg(P[i], P[(i+1) % P.size()], point(x,y));
	}

	printf("%lf\n", M_PI * (D * D - d * d));
}
