#include<iostream>
#include<cstdio>
using namespace std;
#define ull unsigned long long

ull d_sum = 0;

ull digit_sum(ull n) {
	ull s = 0;
	while (n != 0)
	{
		s += n % 10;
		n /= 10;
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	/*
	d_sum = 0;
	ull count = 0;
	for (ull i = 1; i <= 100; i++) {
		d_sum += digit_sum(i);
		if (d_sum % 3 == 0) {
			cout << i << "\ttrue\n";
		}
		else {
			cout << i << "\tfalse\n";
		}
	}
	*/
	ull l, r,t,r1,r2;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> l >> r;
		l--;
		if (l % 3 == 0)
			r1 = l - (l / 3);
		else
			r1 = l - (l / 3 + 1);
		
		if (r % 3 == 0)
			r2 = r - (r / 3);
		else
			r2 = r - (r / 3 + 1);
		cout << "Case " << tc << ": " << r2 - r1 << "\n";
	}
	return 0;
}