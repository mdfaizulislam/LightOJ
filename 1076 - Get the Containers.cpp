#include<iostream>
#include<cstdio>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define MAX 999999
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned long ul;
typedef long l;

int n, con;
ll vesels[1001];
ll mx;
bool covered(ll capacity) {
	if (capacity < mx )
		return false;
	int co = 0;
	ll s = 0;
	s += vesels[0];
	for (int i = 1; i < n; i++) {		// 1 2 3 4 5
										// 4 78 9
		if (s + vesels[i] <= capacity) {
			s += vesels[i];
		}
		else {
			co++;
			s = vesels[i];
		}
		if (n - i == 1) {
			co++;
		}
	}
	if (co <= con)
		return true;
	return false;
}
int main() {
	int t;
	cin >> t;
	for (int Case = 1; Case <= t; Case++) {
		cin >> n >> con;
		ll mn_con = MAX, mx_con = 0;
		mx = -1;
		for (int i = 0; i < n; i++) {
			cin >> vesels[i];
			mx_con += vesels[i];
			mn_con = vesels[i] < mn_con ? vesels[i] : mn_con;
			mx = vesels[i] > mx ? vesels[i] : mx;
		}

		ll low = mn_con, high = mx_con, mid;
		ll ans;
		while (high - low > 2) {
			mid = low + (high - low)*0.5;
			if (covered(mid)) {
				ans = mid;
				high = mid;
			}
			else
			{
				low = mid;
			}
		}
		ll i = high;
		while (covered(i))
		{
		ans = i;
		i--;
		}

		cout << "Case " << Case << ": " <<  ans << "\n";
	}
	return 0;
}
