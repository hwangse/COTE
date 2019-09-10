#include<iostream>

using namespace std;

int p[10001] = { 0 };
int Max[10001] = { 0 };

int main() {
	int n;

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> p[i];

	Max[1] = p[1];

	for (int i = 2; i <= n; i++) {
		int tmp = -1;
		for (int j = 1; j <= i / 2; j++) {
			int res = Max[j] + Max[i - j];
			if (res > tmp)
				tmp = res;
		}
		Max[i] = tmp > p[i] ? tmp : p[i];
	}
	cout << Max[n] << '\n';

	return 0;
}