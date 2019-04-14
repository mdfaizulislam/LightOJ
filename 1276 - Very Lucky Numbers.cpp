#include <iostream>

using namespace std;
long veryLucky[100000];
bool divisibleby(int n) {
	if (n == 1)
		return false;
	while (n > 1) {
		if (n % 4 == 0) {
			n /= 4;
		}
		else if (n % 7 == 0) {
			n /= 7;
		}
		else
			return false;
	}
	return true;
}

bool consists_of(int n) {
	int t;
	while (n != 0) {
		t = n % 10;
		n /= 10;
		if (t == 4)
			continue;
		else if (t == 7)
			continue;
		else
			return false;
		
	}
	return true;
}
int main()
{
	//freopen("out.txt", "w", stdout);
	int t, a, b, cnt=0;
	bool f, g;
	//cout << consists_of(7);
	//cout << divisibleby(49);
	for (long k = 4; k <= 1000000000000; k++) {
		f = divisibleby(k);
		g = consists_of(k);
		if (f || g)
		{
			veryLucky[cnt++] = k;
			cout << k << "\n";
		}
	}

	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> a >> b;
		cnt = 0;
		for (int k = a; k <= b; k++) {
			f = divisibleby(k);
			g = consists_of(k);
			if (f || g)
				cnt++;
		}
		cout << "Case " << i << ": " << cnt << "\n";
	}
	return 0;
}
