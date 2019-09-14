#include<iostream>

using namespace std;

/*
* BOJ 11727 2*n 타일링 2 (dp algorithm)
* 해결 : 11726 2*n 타일링1 과 10844 쉬운계단수 (모듈러 연산) 을 적절히 섞어서 풀면 됨.
*/

long long dp[1001] = { 0 };

int main() {
	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; i++) 
		dp[i] = dp[i - 1]%10007 + (dp[i - 2] * 2)%10007;

	cout << dp[n]%10007 << '\n';

	return 0;
}