#include<iostream>
#include<string>

using namespace std;

int main() {
	string word;
	cin >> word;

	for (string::iterator it = word.begin(); it != word.end(); ++it) {
		if ('A' <= *it && *it <= 'C') {
			*it = *it - 'A' + 'X';
		}
		else
			*it = *it - 3;
	}
	cout << word << '\n';

	return 0;
}