#include<iostream>

using namespace std;

/*
* BOJ 2167 2차원 배열의 합 (dp algorithm)

* 문제 : (a,b) 부터 (c,d) 까지의 배열의 합을 구하는 문제 (사각형모양부분)
* 해결 : TC가 1개일 경우 일일이 다 계산해도 되지만, 테스트 케이스가 많아질 경우
		 다 계산하는건 시간적으로 낭비이므로 시간을 줄이기 위해 dp 알고리즘의 memoization을 이용해야한다.
		 배열의 입력값을 받을 때, 동시에 (0,0)의 위치에서부터 현재 받는 배열 값까지의 총 합을 동시에 저장하면
		 나중에 (a,b) 부터 (c,d)까지의 값을 계산할 때, O(1)의 시간 복잡도로 원하는 값을 구할 수 있다. 
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