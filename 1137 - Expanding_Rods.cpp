#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define ull				unsigned long long
#define ll				long long
#define ul				unsigned long
#define min(a,b)		((a)<(b)?(a):(b))
#define max(a,b)		((a)>(b)?(a):(b))
#define pi				acos(-1.0)
#define mod				10000000007
#define precision		0.0000000001
double l, l_dash, temp_change, coeff, radious, c;

double curve_length(double h) {
	double radious = (c*c) / (2*h) + h/2;
	double theta = 2 * asin(c / radious);
	return radious*theta;
}
int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		scanf_s("%lf %lf %lf", &l, &temp_change, &coeff);

		l_dash = (1.0 + temp_change*coeff)*l;

		c = l*0.5;

		double low = 0.0, high = l, mid;

		for(int i = 0 ; i < 64 ; i++)
		{
			mid = (high + low)*0.5; // mid = h
			
			if (curve_length(mid) > l_dash ){
				high = mid;
			}
			else {
				low = mid;
			}
		}
		printf_s("Case %d: %lf\n", tc, mid);
	}
	return 0;
}

