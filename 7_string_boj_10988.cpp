#include<iostream>
#include<string>

using namespace std;

int main() {
	string word;
	bool res = true;

	cin >> word;

	for (int i = 0; i < word.length() / 2; i++) {
		if (word.at(i) != word.at(word.length() - 1 - i)) {
			res = false; break;
		}
	}

	if (res)
		cout << "1\n";
	else
		cout << "0\n";

	return 0;
}