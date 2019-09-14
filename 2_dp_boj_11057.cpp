#include<iostream>

using namespace std;

int number[10] = { 0 };

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < 10; i++)
		number[i] = 1;

	for (int i = 3; i <= n; i++) {
		int temp_number[10] = { 0 };
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++)
				temp_number[k] += (number[j]%10007);
		}
		for (int j = 0; j < 10; j++)
			number[j] = temp_number[j];
	}

	if (n == 1)
		cout << "10\n";
	else {
		int res = 0;
		for (int i = 0; i < 10; i++)
			res += number[i]*(10-i);
		cout << res%10007 << endl;
	}

	return 0;
}