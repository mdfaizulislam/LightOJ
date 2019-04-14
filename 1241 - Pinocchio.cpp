#include<iostream>
using namespace std;
const int MAX = 55;

int main() {
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	int res = 0;
	int prev, report;
	int n, a;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		res = 0;
		prev = 2;
		for (int i = 0; i < n; i++) {
			cin >> report;
			if (report > prev) {
				a = report - prev;
				res += a / 5;
				if (a % 5) {
					res++;
				}
				prev = report;
			}
		}
		cout << "Case " << tc << ": " << res << "\n";
	}
	return 0;
}