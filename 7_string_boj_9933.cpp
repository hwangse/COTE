#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int n;
	char letter;
	int ans;
	cin >> n;
	vector<string> str_array(n);

	for (auto&element : str_array)
		cin >> element;

	for (int i = 0; i < n; i++) {
		string str = str_array.at(i);

		int len = str.length();
		string str_cp = str;
		for (int j = 0; j < len / 2; j++) {
			char letter=str_cp.at(j);
			str_cp.at(j) = str_cp.at(len - 1 - j);
			str_cp.at(len - 1 - j) = letter;
		}

		sort(str_array.begin(), str_array.end());

		bool find = false;
		if (binary_search(str_array.begin(), str_array.end(), str_cp)) {
			find = true;
			ans = str_cp.length();
			letter = str_cp.at(ans / 2);
			break;
		}
		if (find) break;
	}
	cout << ans << ' ' << letter << endl;

	return 0;
}