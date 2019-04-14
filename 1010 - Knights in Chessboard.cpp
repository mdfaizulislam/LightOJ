#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define min(a,b)	((a)<(b)?(a):(b))
#define max(a,b)	((a)>(b)?(a):(b))
#define abs(a)		((a)<0?-(a):(a))
#define mod			1000000007
#define MAX			INT_MAX
#define MIN			INT_MIN
#define ull			unsigned long long
#define ll			long long
#define ul			unsigned long
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
	long n, m, ans;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m;
		if (n == 1 || m == 1)
			ans = m*n;
		else if (n == 2 || m == 2) {
			if (n == 2)
				ans = m;
			else
				ans = n;
			if (ans % 4 == 1)
				ans++;
			else if (ans % 4 == 2)
				ans += 2;
			else if (ans % 4 == 3)
				ans++;
		}
		else if (m*n % 2 == 0)
			ans = (m*n) / 2;
		else {
			ans = (m*n + 1) / 2;
		}
		cout << "Case " << tc << ": " << ans << "\n";
	}
	return 0;
}
