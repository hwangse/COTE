#include<iostream>
#include<string>
#include<array>

using namespace std;

int main() {
	int n;
	string pattern;
	cin >> n;
	cin.ignore(37000, '\n');

	cin >> pattern;

	int len = pattern.length();
	
	for (int i = 0; i < n - 1; i++) {
		string current;
		cin >> current;
		
			for (int j = 0; j < len; j++) {
				if (pattern.at(j) != current.at(j))
					pattern.at(j) = '?';
			}
		
		
	}

	cout << pattern << '\n';

	return 0;
}