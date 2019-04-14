#include<iostream>
#include<cstdio>
using namespace std;
#define ull				unsigned long long
#define ll				long long
#define ul				unsigned long
#define min(a,b)		((a)<(b)?(a):(b))
#define max(a,b)		((a)>(b)?(a):(b))
#define pi				acos(-1.0)
#define mod				11000000007

int arr[2001];

void merge(int left, int right) {
	if (left < right) {
		int mid = left + ((right - left) >> 1); // left + (right-left)*0.5 or /2
		merge(left, mid);
		merge(mid + 1, right);

		int L, R;
		L = mid - left + 1;
		R = right - mid;

		int *a = (int *)malloc(L * sizeof(int));
		int *b = (int *)malloc(R * sizeof(int));
		
		int j = left;
		for(int i =0; i < L ; i++) {
			a[i] = arr[j++];
		}

		j = mid + 1;
		for( int i =0; i < R; i++) {
			b[i] = arr[j++];
		}

		int i = 0, k = left;
		j = 0;
		while (i < L && j < R) {
			if (a[i] <= b[j]) {
				arr[k++] = a[i++];
			}
			else {
				arr[k++] = b[j++];
			}
		}

		while (i < L )
		{
			arr[k++] = a[i++];
		}

		while (j < R )
		{
			arr[k++] = b[j++];
		}
		free(a);
		free(b);
	}
}

int BS(int left, int right, int value) {
	int mid;
	int hightest_min_index = left-1; // if c is besides of b & c is in the last index
	while (left <= right) {
		mid = left + ((right - left) >> 1);
		if (arr[mid] < value) {
			hightest_min_index = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return hightest_min_index;
}
int main() {

	ll t, n;
	cin >> t;
	for (int c = 1; c <= t; c++) {

		cin >> n;
		
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		merge(0, n - 1);
		
		int res = 0;
		for (int i = 0; i < n; i++) {		// a = arr[i] b =arr[j] then find min index
			for (int j = i + 1; j < n; j++) {	// such that a+b > c
				res += BS( j+1, n-1, arr[i] + arr[j]) - j;
			}
		}
		cout << "Case " << c << ": " << res << "\n";
	}
	return 0;
}

