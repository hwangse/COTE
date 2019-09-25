#include<iostream>
#include<string>

using namespace std;

int main() {
	string word;
	cin >> word;

	int count = 0;
	int len = word.length();

	for (int i = 0; i < word.length(); i++) {
		char tmp = word.at(i);
		if (tmp == 'C' || tmp == 'A' || tmp == 'M' || tmp == 'B' || tmp == 'R' || tmp == 'I'
			|| tmp == 'D' || tmp == 'G' || tmp == 'E') {
			count += 1;
		}
		else {
			if (count > 0)
				word.at(i - count) = word.at(i);
		}
	}
	word.resize(len - count);
	cout << word << '\n';

	return 0;
}