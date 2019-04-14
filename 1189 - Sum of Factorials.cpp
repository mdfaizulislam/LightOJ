//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#define ull unsigned long long
const int MAX = 100;
ull fact[MAX];

void factorial() {
	fact[0] = 1;
	for (ull i = 1; i <= 21; i++) {
		fact[i] = fact[i - 1] * i;
		//cout << i << "\t" << fact[i] << "\n";
	}
}

bool solve(ull n, bool *used) {
	for (int i = 21; i >= 0; i--) {
		if ( fact[i] > n)
			continue;
		if ( fact[i] <= n ) {
			n -= fact[i];
			used[i] = true;
		}
		if (n == 0)
			return true;
	}

	return false;
}
int main() {
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	factorial();

	int T;
	ull n;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;

		cout << "Case " << tc << ": ";
		
		bool used[22] = { false };
		
		if (solve(n, used)) {
			
			bool first = true;
		
			for (int i = 0; i <= 21; i++) {
			
				if (used[i]) {
					if (first) {
						cout << i << "!";
						first = false;
					}
					else {
						cout << "+" << i << "!";
					}
				}
			}
		}
		else
			cout << "impossible";
		
		cout << "\n";
	}
	return 0;
}