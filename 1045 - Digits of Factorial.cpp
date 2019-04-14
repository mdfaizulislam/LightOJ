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

double logg[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	//cin.tie(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	for (int i = 1; i < 1000001; i++)
		logg[i] = logg[i - 1] + log(i);
	int t;
	int n, b;
	ll ans;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> b;
		ans = logg[n] / log(b) + 1;
		cout << "Case " << tc << ": " << ans << "\n";
	}
	return 0;
}
