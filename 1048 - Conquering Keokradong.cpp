#include<iostream>
#include<cstdio>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned long ul;
typedef long l;
int n, k;
int arr[1001];
bool can_cover(int walking_dist) {
	int s = arr[0], covered=0;
	for (int i = 1; i <= n; i++) {
		if (arr[i] > walking_dist)
			return false;
		if (arr[i] + s <= walking_dist) {
			s += arr[i];
		}
		else {
			s = arr[i];
			covered++;
		}
	}
	if (covered <= k)
		return true;
	return false;
}

int main() {
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> k;
		int mx = 0, mn = -1; 
		for (int j = 0; j <= n; j++) {
			cin >> arr[j];
			mx += arr[j];
			mn = arr[j] > mn ? arr[j] : mn;
		}
		int mid;
		int ans = 0;
		while (mx - mn > 2)
		{
			mid = mn + (mx - mn) / 2;
			if (can_cover(mid)) {
				ans = mid;
				mx = mid;
			}
			else {
				mn = mid;
			}
		}
		
		for (int c = mx; c >= mn; c--) {
			if (can_cover(c))
				ans = c;
		}
		cout << "Case " << i << ": " << ans << "\n";

		int s = arr[0], covered=0, c;
		for (c = 1; c <= n; c++) {
			if (s + arr[c] <= ans) {
				s += arr[c];
			}
			else {
				cout << s << "\n";
				s = arr[c];
				covered++;
			}
			if ( k - covered >= n-c ) {
				cout << s << "\n";
				for (int j = c + 1; j <= n; j++) {
					cout << arr[j] << "\n";
				}
				break;
				
			}
		}
		
	}
	return 0;
}

