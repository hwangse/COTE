#include<iostream>
#include<string>

using namespace std;

int main() {
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		string strA, strB;
		cin >> strA >> strB;

		cout << "Distances: ";
		for (int i = 0; i < strA.length(); i++) {
			int temp;
			temp = strB.at(i) - strA.at(i);
			if (temp < 0) temp += 26;

			if (i != strA.length() - 1)
				cout << temp << ' ';
			else
				cout << temp << '\n';
		}
	}

	return 0;
}