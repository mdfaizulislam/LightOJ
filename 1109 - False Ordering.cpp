#include <iostream>
#include <algorithm>
using namespace std;
long factors[1001] = { 0 };
long pos[1001];
void preCalcDivisors() {
	long count = 0;
	long n = 0;
	long divisors = 1;
	for (long j = 1; j <= 1001; j++) {
		
		count = 0;
		n = j;
		divisors = 1;
		for (long i = 2; i*i <= n; i++) {
			count = 0;
			while (n%i == 0)
			{
				n /= i;
				count++;
			}
			if (count) {
				count++;
				divisors *= count;
			}
		}
		if (n > 1) {
			count = 1;
			count++;
			divisors *= count;
		}
		factors[j] = divisors;
	}
}

bool myfunc(long i, long j) {
	if(factors[i] == factors[j])
		return j < i;
	return factors[i] < factors[j];
}
int main() {
	ios_base::sync_with_stdio(false);
	preCalcDivisors();
	for (int i = 0; i < 1000; i++)
		pos[i] = i + 1;
	sort(pos, pos + 1000, myfunc);
	int t, n;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		cout << "Case " << tc << ": " << pos[n - 1] << "\n";
	}
}