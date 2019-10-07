#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	int n;
	int count = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string word;
		stack<char> s;
		char dLetter;
		cin >> word;
		int goodPair = 0;

		s.push(word.at(0));
		int idx = 1;

		while (idx<word.length()) {
			if (goodPair >0 && dLetter == word.at(idx)) {
				idx++; continue;
			}
			if (s.empty()) {
				s.push(word.at(idx++));
				continue;
			}

			if (word.at(idx) == s.top()) {
				s.pop(); goodPair += 1;
				dLetter = word.at(idx);
			}
			else
				s.push(word.at(idx));
			idx += 1;

			if (goodPair == 2) {
				count += 1; break;
			}
			if (idx >= word.length()) break;
		}


		//cout << "good Pair : " << goodPair << endl;
	}
	cout << count << '\n';

	return 0;
}