#include<iostream>
#include<string>

using namespace std;

int main() {
	string str1, str2;

	cin >> str1 >> str2;

	int Min = 50;
	int repeat = str2.length() - str1.length() + 1;

	for (int i = 0; i < repeat; i++) {
		int count = 0;

		for (int j = i; j < i + str1.length(); j++) {
			if (str1[j-i] != str2[j]) count += 1;
		}
		if (count < Min) Min = count;
	}
	cout << Min << '\n';

	return 0;
}