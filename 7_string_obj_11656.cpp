#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<string> postfix;
	string word;
	cin >> word;

	for (int i = 0; i < word.length();i++) 
		postfix.push_back(word.substr(i));
	
	sort(postfix.begin(), postfix.end());

	for (auto &element : postfix)
		cout << element << '\n';

	return 0;
}