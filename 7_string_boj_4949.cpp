#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	string str;

	while (1) {
		getline(cin, str);
		stack<char> s;
		bool balance_flag = true;

		if (str == ".") break;

		for (int i = 0; i < str.length(); i++) {
			char a = str.at(i);
			if (a == '(' || a == '[') s.push(a);
			else if (a == ')') {
				if (!s.empty() && s.top() == '(') {
					s.pop();
				}
				else balance_flag = false;
			}
			else if (a == ']') {
				if (!s.empty() && s.top() == '[') {
					s.pop();
				}
				else balance_flag = false;
			}
		}

		if (!s.empty()) balance_flag = false;
		
		if (balance_flag) cout << "yes\n";
		else cout << "no\n";
	}


	return 0;
}