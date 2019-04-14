#include <iostream>
#include <stack>
#include <cstdio>
#include<string>
using namespace std;

string choice;
int turn;

int main()
{
	ios_base::sync_with_stdio(false);

	int t;
	string url;
	stack <string> f;
	stack <string> b;

	cin >> t;

	for (int cs = 1; cs <= t; cs++) {
		cin >> choice;
		while (!b.empty()) {
			b.pop();
		}

		while (!f.empty()) {
			f.pop();
		}

		url = "http://www.lightoj.com/";
		cout << "Case " << cs << ":\n";
		while (choice != "QUIT") {

			if (choice == "VISIT")
				turn = 0;
			else if (choice == "FORWARD")
				turn = 1;
			else if (choice == "BACK")
				turn = 2;

			switch (turn) {
				//vis for back
			case 0:
				b.push(url);
				cin >> url;
				cout << url << "\n";
				while (!f.empty()) {
					f.pop();
				}
				break;

			case 1:
				if (f.empty()) {
					cout << "Ignored\n";
				}

				else {
					b.push(url);
					url = f.top();
					f.pop();
					cout << url << "\n";
				}
				break;


			case 2:

				if (b.empty()) {
					cout << "Ignored\n";
				}

				else {
					f.push(url);
					url = b.top();
					b.pop();
					cout << url << "\n";
				}

				break;
			}
			cin >> choice;
		}
	}
}
