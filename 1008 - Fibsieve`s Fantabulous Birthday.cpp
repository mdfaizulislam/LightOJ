#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define min(a,b)    ((a)<(b)?(a):(b))
#define max(a,b)    ((a)>(b)?(a):(b))
#define abs(a)      ((a)<0?-(a):(a))
#define mod         1000000007
#define MAX         INT_MAX
#define MIN         INT_MIN
#define ull         unsigned long long
#define ll          long long
#define ul          unsigned long
/*

double sqrt(double n) {
double low = 0, high = n, mid;
for (int i = 0; i < 64; i++) {
mid = (low + high) / 2.0;
if (mid*mid <= n)
low = mid;
else
high = mid;
}
return mid;
}
*/


int main() {
	ios_base::sync_with_stdio(false);
	//cin.tie(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t;
	cin >> t;
	ull n, root;
	ull x, y;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		root = sqrt(n);
		if (n > root*root && n <= (root + 1)*(root + 1)) {
			ull mid = (root*root + 1);
			root++;
			mid += root*root;
			mid /= 2;
			x = root;
			y = root;
			if (root % 2 == 1) {
				if (n > mid) {
					y -= (n - mid);
				}
				else if (n < mid) {
					x -= mid - n;
				}
			}
			else {
				if (n > mid) {
					x -= n - mid;
				}
				else if (n < mid) {
					y -= mid - n;
				}
			}
		}
		else if (root*root == n) {
			if (root % 2 == 1) {
				x = root;
				y = 1;
			}
			else {
				x = 1;
				y = root;
			}
		}
		cout << "Case " << tc << ": " << y << " " << x << "\n";
	}
	return 0;
}
