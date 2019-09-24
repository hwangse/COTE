#include<iostream>
#include<string>
#include<array>
#include<vector>
#include<set>]
#include<algorithm>
#include<cstdio>

using namespace std;

bool Comp(string a, string b) {
		return a < b;
}

int main() {
	array<bool, 500000> checked = { false };
	vector<string> hearing;
	vector<string> watching;
	vector<string> hearAndWatch;
	set<string> sortedStrings;

	int n, m;
	cin >> n >> m;

	// resize 가 push_back 보다 훨씬 빠르다. 미리 메모리를 할당해서
	hearing.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> hearing[i];
	}
	sort(hearing.begin(),hearing.end());

	for (int i = 0; i < m; i++) {
		string tmp;
		cin >> tmp;

		if (binary_search(hearing.begin(), hearing.end(), tmp))
			hearAndWatch.push_back(tmp);
	}

	sort(hearAndWatch.begin(), hearAndWatch.end());
	cout << hearAndWatch.size() << '\n';
	for (auto &element : hearAndWatch)
		cout << element << '\n';

	return 0;
}