#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	string str;
	vector<char> finalStr;

	getline(cin, str);

	for (int i = 0; i < str.length(); i++) {
		char tmp = str.at(i);
		if ('A' <= tmp && tmp <= 'Z') finalStr.push_back(tmp);
	}

	for (auto& element : finalStr)
		cout << element;
	cout << '\n';

	return 0;
}