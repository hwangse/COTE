#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	int maxLIS = 0;
	vector<int> children(n, 0);
	vector<int>LIS(n, 0);

	for (auto &element : children)
		cin >> element;

	// O(n^2)
	LIS[0] = 1;
	for (int i = 1; i < n; i++) {
		int tmpMax = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (children[j] < children[i] && tmpMax < LIS[j])
				tmpMax = LIS[j];
		}
		LIS[i] = tmpMax + 1;
		if (LIS[i] > maxLIS)
			maxLIS = LIS[i];
	}
	cout << n-maxLIS << '\n';

	return 0;
}