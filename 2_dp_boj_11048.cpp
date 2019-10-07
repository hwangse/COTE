#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> candy(n,vector<int>(m,0));
	vector<vector<int>> dp(n,vector<int>(m,0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> candy[i][j];
	}

	dp[0][0] = candy[0][0];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) continue;
			int tmpMax = -1;
			if (j > 0 && dp[i][j - 1] > tmpMax) tmpMax = dp[i][j - 1];
			if (i > 0 && dp[i - 1][j] > tmpMax) tmpMax = dp[i - 1][j];
			if (j > 0 && i > 0 && dp[i - 1][j - 1] > tmpMax) tmpMax = dp[i - 1][j - 1];
			
			dp[i][j] = tmpMax + candy[i][j];
		}
	}
	cout << dp[n - 1][m - 1] << endl;

	return 0;
}