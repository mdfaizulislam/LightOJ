#include<iostream>
#include<cstdio>
#include<malloc.h>

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


int main() {
	ios_base::sync_with_stdio(false);
	//cin.tie(false);
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t;
	long n, even;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		even = 1;
		while (n)
		{
			if (!(n & 1)) {
				even <<= 1;
				n >>= 1;
				if (n & 1) {
					cout << "Case " << tc << ": " << n << " " << even << "\n";
					break;
				}
			}
			else {
				cout << "Case " << tc << ": " << "Impossible\n";
				break;
			}
		}
	}
	return 0;
}
