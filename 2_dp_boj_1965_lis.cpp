#include<iostream>

using namespace std;

/*
* BOJ 11053 : LIS algorithm (���� �κ� �������� )

* ���� : �־��� n���� �� �߿��� ���� �� �κ� �������� ���ϱ�
* �ذ� : ���� ���Һ��� �տ� �ִ� ���� ��
		 1. ���� ���Һ��� �����鼭
		 2. ���� ū �κ� ���� ��(len)�� ���� ����
		 �� ã�Ƽ� +1 �� ���� ��, ���� ������ len ������ �������ش�. 
* ������ �� : �������� �������� �� ������ ������ len ���� ������ �������µ� �� ������ ������
			  len���� ���� ū ���� �κ� �������̶�� ���Ű� 1�� ����. �� ��� len �迭�� ��ȸ�ϸ鼭 ���� ū 
			  ���� ���� ��ü�� ������ �ȴ�. 
*/

int arr[1001] = { 0 };
int len[1001] = { 0,1, };

int main() {
	int n;
	int max_len = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 2; i <= n; i++) {
		int tempMax = 0;
		for (int j = i - 1; j >= 1; j--) {
			if (arr[j] < arr[i]) {
				if (len[j] > tempMax)
					tempMax = len[j];
			}
		}
		if (tempMax > 0)
			len[i] = tempMax + 1;
		else
			len[i] = 1;
	}

	int Max = 0;

	for (int i = 1; i <= n; i++) {
		if (len[i] > Max)
			Max = len[i];
	}
	cout << Max << '\n';

	return 0;
}