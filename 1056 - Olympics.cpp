#include<iostream>
#include<cstdio>
#include <cmath>
using namespace std;
#define ull				unsigned long long
#define ll				long long
#define ul				unsigned long
#define min(a,b)		((a)<(b)?(a):(b))
#define max(a,b)		((a)>(b)?(a):(b))
#define pi				acos(-1.0)
#define mod				10000000007

int main() {
	int t;
	cin >> t;
	double r, theta, s, ratio;
	double a, b;
	for (int tc = 1; tc <= t; tc++) {
		scanf_s("%lf : %lf", &a, &b);
		r = sqrt(a*a + b*b)/2.0;
		theta = acos((r*r + r*r - b*b) / (2.0*r*r));
		s = r*theta;
		ratio = 400.0 / (2.0*a + 2.0*s);
		printf_s("Case %d: %.10lf %.10lf\n", tc, a*ratio, b*ratio);
	}
	return 0;
}
