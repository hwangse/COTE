#include<iostream>

using namespace std;

/*
* BOJ 2167 2���� �迭�� �� (dp algorithm)

* ���� : (a,b) ���� (c,d) ������ �迭�� ���� ���ϴ� ���� (�簢�����κ�)
* �ذ� : TC�� 1���� ��� ������ �� ����ص� ������, �׽�Ʈ ���̽��� ������ ���
		 �� ����ϴ°� �ð������� �����̹Ƿ� �ð��� ���̱� ���� dp �˰����� memoization�� �̿��ؾ��Ѵ�.
		 �迭�� �Է°��� ���� ��, ���ÿ� (0,0)�� ��ġ�������� ���� �޴� �迭 �������� �� ���� ���ÿ� �����ϸ�
		 ���߿� (a,b) ���� (c,d)������ ���� ����� ��, O(1)�� �ð� ���⵵�� ���ϴ� ���� ���� �� �ִ�. 
*/

int arr[301][301] = { 0 };
int from00[301][301] = { 0 };

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int rowSum = 0;
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			rowSum += arr[i][j];
			from00[i][j] = from00[i - 1][j] + rowSum;
		}
	}


	int testcase;
	cin >> testcase;

	for (int a = 1; a <= testcase; a++) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		i -= 1; j -= 1;

		int arrSum = from00[x][y] - from00[i][y] - from00[x][j] + from00[i][j];
		cout << arrSum << '\n';
	}


	return 0;
}