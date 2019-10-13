#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<vector<char>> mirror(100, vector<char>(100, 0));
	vector<vector<char>> res(100, vector<char>(100, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> mirror[i][j];
	}

	int feel;
	cin >> feel;

	if (feel == 1);
	else if (feel == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n / 2; j++) {
				char tmp = mirror[i][j];
				mirror[i][j] = mirror[i][n - 1 - j];
				mirror[i][n - 1 - j] = tmp;
			}
		}
	}
	else {
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n / 2; i++) {
				char tmp = mirror[i][j];
				mirror[i][j] = mirror[n-1-i][j];
				mirror[n-1-i][j] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << mirror[i][j];
		cout << endl;
	}

	return 0;
}