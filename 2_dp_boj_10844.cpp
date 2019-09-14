#include<iostream>

using namespace std;

/*
* BOJ 10844 ������ �� (dp algorithm)

* ���� : 1<= n <=100�� n (������ ���� ��) �� �־��� ��, n�ڸ� ���� ��� ���� ������ ���ϴ� ����
* ������ �� : 8byte�� long long �ڷ����� 100�ڸ��� ������ ������ ���ϹǷ� �߰��� ����� ��, 
			  ������ ������ ������ �����ؾ���. 
			  (A+B)%C = (A%C+A%B)%C ���� �̿�.
* �ذ� : ������ dp ��ȭ���� �����س���� ����� X. �ٸ� ��ⷯ ������ �����ʿ����� �����ϴ°� �� ���.
         +) �۰� �� �ٺ����� �迭���� �����ؼ� �߸������Ѱ� �Ѱ��� �־ ��� Ʋ��;

*/

long long stair[101] = { 0 };
long long number[10] = { 0 };

#define BIG_NUM 1000000000

int main() {
	int n;

	cin >> n;

	stair[1] = 9;
	for (int i = 1; i < 10; i++) number[i] = 1;

	for (int i = 2; i <= n; i++) {
		long long tmp = 0;

		for (int j = 0; j < 10; j++) {
			if (j == 0 || j == 9) tmp += (number[j]);
			else tmp += ((number[j] * 2));
		}

		stair[i] = tmp;

		long long tmp_number[10] = { 0 };

		for (int j = 0; j < 10; j++) {
			if (j == 0)
				tmp_number[j + 1] += (number[j] % BIG_NUM);
			else if (j == 9)
				tmp_number[j - 1] += (number[j] % BIG_NUM);
			else {
				tmp_number[j + 1] += (number[j] % BIG_NUM);
				tmp_number[j - 1] += (number[j] % BIG_NUM);
			}
		}

		for (int j = 0; j < 10; j++)
			number[j] = tmp_number[j];

	}

	cout << stair[n] % BIG_NUM << '\n';

	return 0;
}