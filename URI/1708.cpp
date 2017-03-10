#include <cstdio>
#include <cmath>

int main()
{
	int X, Y;
	scanf("%d %d\n", &X, &Y);
	printf("%d\n", (int)ceil((double)(Y)/(Y-X)));
}
