#include<iostream>

using namespace std;

bool a[51][51] = { false };
bool b[51][51] = { false };

int main() {
	int n, m;
	cin >> n >> m;
	bool flag = true;

	//get matrix A and B
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char tmp;
			cin >> tmp;
			if (tmp == '1')
				a[i][j] = true;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char tmp;
			cin >> tmp;
			if (tmp == '1')
				b[i][j] = true;

			if (a[i][j] != b[i][j])
				flag = false;
		}
	}

	int res;
	int convert = 0;

	if (n < 3 || m < 3) {
		if (!flag)
			cout << "-1\n";
		else
			cout << "0\n";
	}
	else { //n>=3 and m>=3 일 때
		bool all_same = true;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (a[i][j] != b[i][j]) {
					//3*3 연산 가능한 상황
					if (i + 2 <= n && j + 2 <= m) {
						convert += 1;
						for (int y = i; y <= i + 2; y++) {
							for (int x = j; x <= j + 2; x++) {
								if (a[y][x]) a[y][x] = false;
								else a[y][x] = true;
							}
						}
					}
					// 연산 불가 상황
					else {
						all_same = false;
					}
				}
			}
		}
		if (!all_same)
			res = -1;
		else
			res = convert;

		cout << res << '\n';

	}


	return 0;
}