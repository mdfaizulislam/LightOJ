#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int N, K;

void permute(int length, bool *used, string str) {

	if (K == 0) return;

	if (length == N) {
		cout << str << endl;
		K--;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!used[i]) {
			string temp = str;
			temp += (char)(i + 'A');
			used[i] = true;
			permute(length + 1, used, temp);
			used[i] = false;
		}
	}
}


int main() {

	int T;
	cin >> T;
	for (int c = 1; c <= T; c++) {
		cin >> N >> K;
		bool used[27];
		memset(used, false, sizeof used);
		cout << "Case " << c << ":" << "\n";
		permute(0, used, "");
	}

	return 0;
}