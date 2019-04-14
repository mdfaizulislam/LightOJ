#include<iostream>
#include<cstdio>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned long ul;
typedef long l;

int count_zeros(int n) {
	int t = 0;
	for (int i = 5; n / i >= 1; i *= 5)
		t += n / i;
	return t;
}

int natural_n(int q) {
	int l = 0, r = INT32_MAX;
	int mid, zeros;
	while (l <= r )
	{
		mid = l + (r - l)*0.5;
		zeros = count_zeros(mid);
		if (zeros == q) {
			while (count_zeros(mid) == q )
			{
				mid--;
			}
			return ++mid;
		}
		else if (zeros > q)
			r = mid-1;
		else
			l = mid+1;
	}
	return 0;
}
int main() {
	
	int t, q, ans;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> q;
		ans = natural_n(q);
		if (ans != 0)
			cout << "Case " << i << ": " << ans << "\n";
		else
			cout << "Case " << i << ": " << "impossible\n";
	}
	return 0;
}

