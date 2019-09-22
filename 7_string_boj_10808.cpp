#include<iostream>
#include<string>
#include<array>

using namespace std;

int main() {
	array<int, 26> alphabet = { 0 };
	string word;
	cin >> word;

	for (int i = 0; i < word.length(); i++)
		alphabet[word.at(i) - 'a'] += 1;

	for (auto&element : alphabet)
		cout << element << ' ';
	cout << '\n';
	
	return 0;
}