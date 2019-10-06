#include<iostream>
#include<string>

using namespace std;

int main() {
	string str;
	cin >> str;

	int count1 = 0, count2 = 0;

	for (int i = 0; i < str.length(); i++) {
		if ((str.at(i) == 'J' || str.at(i) == 'I') && i + 2 < str.length()) {
			if (str.at(i + 1) == 'O' && str.at(i + 2) == 'I') {
				if (str.at(i) == 'J') count1++;
				else count2++;

				i++;
			}
		}
	}
	cout << count1 << endl;
	cout << count2 << endl;

	return 0;
}