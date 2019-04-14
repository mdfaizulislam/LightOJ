#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, nibble, byte;
	int count;
	while (cin>>n)
	{
		nibble = 0, byte = 0, count = 0;
		if (n == 0) {
			cout << 1 << " Bit\n";
			continue;
		}
		while (n!=0)
		{
			count++;
			n >>= 1;
		}
		if (count >= 8) {
			byte = count / 8;
			count -= byte * 8;
			if( count != 0)
				cout << byte << " Byte ";
			else
				cout << byte << " Byte";
		}
		if (count >= 4) {
			nibble = count / 4;
			count -= nibble * 4;
			if (count != 0)
				cout << nibble << " Nibble ";
			else
				cout << nibble << " Nibble";
		}
		if (count > 0) {
			cout << count << " Bit";
		}
		cout << "\n";
	}

	return 0;
}