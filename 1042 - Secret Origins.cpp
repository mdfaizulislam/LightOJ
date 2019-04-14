#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
// not solved
void binary_representation(int n) {
	cout << n << "\t";
	for (int i = 31; i >= 0; i--) {
		if (n & (1 << i))
			cout << 1;
		else
			cout << 0;
	}
	cout << "\n";
}

int count_ones(int n) {
	int cnt = 0;
	while (n != 0)
	{
		if (n & 1)
			cnt++;
		n >>= 1;
	}
	return cnt;
}


int main() {
	ios_base::sync_with_stdio(false);
	int T, n;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		binary_representation(n);
		cout << n << " " << count_ones(n) << "\n";
	}
	return 0;
}