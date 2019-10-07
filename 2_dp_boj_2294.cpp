#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define INT_MAX 2147483647

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> dp(k + 1,0);
	vector<int> coin;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		coin.push_back(tmp);
		if(tmp<=k)
			dp[tmp] = 1;
	}
	sort(coin.begin(), coin.end());
	int m = coin.at(0);

	for (int i = m + 1; i <= k; i++) {
		int tmp_min = INT_MAX;
		if (dp[i] == 1) continue;

		for (int j = 0; j < coin.size(); j++) {
			if (i - coin.at(j) >= m && dp[i - coin.at(j)] < tmp_min && dp[i - coin.at(j)]!=0)
				tmp_min = dp[i - coin.at(j)];
		}
		if(tmp_min < INT_MAX)
			dp[i] = tmp_min + 1;
	}

	if (dp[k] != 0)
		cout << dp[k] << endl;
	else
		cout << -1 << endl;

	return 0;
}