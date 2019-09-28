#include<iostream>
#include<vector>

/*
* BOJ 11051 ���װ�� 2 : dp algorithm
* ���� : ���װ�� nCk �� ���ϴ� ����
* �ذ� : ���丮���Ǫ��, ��ȭ������ Ǫ�� �Ѵ� dp �˰����� ����ϴ� �� ������
		 ���丮���� ���°� ó�� �������� long long�� ��½�����Ű��ٰ� ������. n�� �ִ밡 1000�̹Ƿ�
		 ������ ���� ��ⷯ ������ ����� �˸� Ǯ���� �ְ�����, �� �� �𸣹Ƿ� �׳� ��ȭ���� �̿�
		 
		 (A+B)%C = ((A%C) + (B%C))%C
		 ��� ���� ���� ���� dp �˰��� �� ��ü��.
		 �� �׷����� dp �˰����� �˸� ���ݰԵ�.
*/

using namespace std;

#define NUM 10007

int main() {
	int n, k;
	cin >> n >> k;

	vector<vector<long long>> arr(n+1, vector<long long>(n+1));

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				arr[i][j] = 1;
			else {
				arr[i][j] = (arr[i - 1][j] + arr[i - 1][j - 1])%NUM;
			}
		}
	}
	cout << arr[n][k] << '\n';

	return 0;
}