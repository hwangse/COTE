#include<iostream>

using namespace std;

long long length[101] = { 0,1,1,1,2,2 };

int main() {
	int testcase;

	cin >> testcase;

	for (int i = 1; i <= testcase; i++) {
		int n;

		cin >> n;

		if (n >= 6) {
			for (int j = 6; j <= n; j++) {
				length[j] = length[j - 1] + length[j - 5];
			}
		}

		cout << length[n]<<'\n';
	}

	return 0;
}