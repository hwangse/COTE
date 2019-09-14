#include<iostream>

using namespace std;

/*
* BOJ 11727 2*n Ÿ�ϸ� 2 (dp algorithm)
* �ذ� : 11726 2*n Ÿ�ϸ�1 �� 10844 �����ܼ� (��ⷯ ����) �� ������ ��� Ǯ�� ��.
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