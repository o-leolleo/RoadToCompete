#include <cstdio>
#include <cmath>
#define EPS 1e-7
int p, q, r, s, t, u;

inline double f_(double x) { return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u; }

int main()
{
        while (scanf("%d %d %d %d %d %d\n", &p, &q, &r, &s, &t, &u) != EOF) {
                double ans = 0., a, b, mid;

                a = 0.; b = 1.;

                if( f_(b)*f_(a) <= 0 ) {
                        while (fabs(b - a) > EPS) {
                                mid = (a + b) / 2;

                                if (f_(a) * f_(mid) <= 0.)
                                        b = mid;
                                else
                                        a = mid;
                        }

                        printf("%.4lf\n", mid);
                } else
                        printf("No solution\n");
        }
}
