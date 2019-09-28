#include<iostream>
#include<vector>

/*
* BOJ 11051 이항계수 2 : dp algorithm
* 문제 : 이항계수 nCk 를 구하는 문제
* 해결 : 팩토리얼로푸나, 점화식으로 푸나 둘다 dp 알고리즘을 사용하는 건 맞지만
		 팩토리얼을 쓰는건 처음 느낌부터 long long을 훌쩍넘을거같다고 생각함. n의 최대가 1000이므로
		 곱셈에 대한 모듈러 연산을 제대로 알면 풀수도 있겠지만, 난 잘 모르므로 그냥 점화식을 이용
		 
		 (A+B)%C = ((A%C) + (B%C))%C
		 사실 위의 연산 식이 dp 알고리즘 그 자체임.
		 왜 그런지는 dp 알고리즘을 알면 깨닫게됨.
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