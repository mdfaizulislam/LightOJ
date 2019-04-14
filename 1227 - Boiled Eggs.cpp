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
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t;
	int n, p, q;
	int arr[31];
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> p >> q;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int quantity = 0, weight = 0;
		int i = 1;
		while (quantity + 1 <= p && weight + arr[i - 1] <= q && (i - 1) < n)
		{
			quantity++;
			weight += arr[i - 1];
			i++;
		}

		cout << "Case " << tc << ": " << quantity << "\n";
	}
	
	return 0;
}
