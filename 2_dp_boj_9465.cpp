#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int testcase;
	cin >> testcase;

	for (int a = 0; a < testcase; a++) {
		int n;
		cin >> n;
		vector<vector<int>> sticker(2, vector<int>(n, 0));
		vector<vector<int>> value(3, vector<int>(n, 0));

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> sticker[i][j];
				if (j == 0)
					value[i][j] = sticker[i][j];
			}
		}

		value[2][0] = value[1][0] > value[0][0] ? value[1][0] : value[0][0];
		if (n > 1) {
			value[0][1] = sticker[0][1] + sticker[1][0];
			value[1][1] = sticker[1][1] + sticker[0][0];
			value[2][1] = value[1][1] > value[0][1] ? value[1][1] : value[0][1];
		}


		if (n > 2) {
			for (int j = 2; j < n; j++) {
				for (int i = 0; i < 2; i++) {
					if (i == 0) value[i][j] = max(value[2][j - 2], value[1][j - 1]);
					else value[i][j] = max(value[2][j - 2], value[0][j - 1]);

					value[i][j] += sticker[i][j];
				}
				value[2][j] = max(value[0][j], value[1][j]);
			}
		}

		cout << value[2][n - 1] << '\n';

	}

	return 0;
}