#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	int finalMax = 0;
	cin >> n;

	vector<int> arr(n, 0);
	vector<int> maxSum(n, 0);
	for (auto& element : arr)
		cin >> element;

	// LIS algorithm start O(n^2) complexity
	maxSum[0] = arr[0];
	if (maxSum[0] > finalMax)
		finalMax = maxSum[0];
	for (int i = 1; i < n; i++) {
		int tmpSum = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] > arr[j] && tmpSum < maxSum[j])
				tmpSum = maxSum[j];
		}
		maxSum[i] = tmpSum + arr[i];
		if (maxSum[i] > finalMax)
			finalMax = maxSum[i];
	}
	cout << finalMax << '\n';

	return 0;
}