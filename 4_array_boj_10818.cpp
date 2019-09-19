#include<iostream>
#include<vector>

using namespace std;

vector<int> arr;

int main() {
	int n;
	cin >> n;

	arr.resize(n);

	for (auto&element : arr)
		cin >> element;

	int Max = arr.at(0), Min = arr.at(0);

	for (int i = 1; i < arr.size(); i++) {
		if (arr.at(i) > Max)
			Max = arr.at(i);
		if (arr.at(i) < Min)
			Min = arr.at(i);
	}
	cout << Min << ' ' << Max << endl;

	return 0;
}