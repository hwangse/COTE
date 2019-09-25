#include<iostream>
#include<string>

using namespace std;

int main() {
	string word;
	cin >> word;

	int count = 0;

	for (string::iterator it = word.begin(); it != word.end(); ++it) {
		switch (*it) {
		case 'a': case 'e': case 'i': case 'o': case 'u': count++; break;
		}
	}
	
	cout << count << '\n';

	return 0;
}