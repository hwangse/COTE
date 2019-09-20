#include<iostream>
#include<array>

/*
* BOJ 2748 �Ǻ���ġ�� 2 : dp algorithm
* ���� : n�� �־����� n ��° �Ǻ���ġ���� ���ϴ� ����
* �ذ� : ��û ������ ������ �� ������� ������ �����ؼ� 
		 ���� ū TC�� n=90�� �־����� int �� �迭�� ����� ���ó� �����ʰ�.
		 �׷��� �ٷ� long long ���� ������.
*/

using namespace std;

int main() {
	array<long long, 91>fibo = { 0,1, };

	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	cout << fibo[n] << endl;

	return 0;
}