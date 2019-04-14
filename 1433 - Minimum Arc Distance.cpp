#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
	int T;
	double ox, oy, ax, ay, bx, by;
	double r_squqre, ab_square, theta;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> ox >> oy >> ax >> ay >> bx >> by;

		r_squqre = pow(abs(ox - bx), 2) + pow(abs(oy - by), 2);
		ab_square = pow(abs(ax - bx), 2) + pow(abs(ay - by), 2);

		theta = acos((2.0*r_squqre - 1.0*ab_square) / (2.0*r_squqre));

		printf("Case %d: %.7lf\n", tc, sqrt(r_squqre)*theta);
	}
	return 0;
}