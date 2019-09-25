#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<string> hear,res;
	// 시간 절약 1. push_back 대신에 resize(n) -> 미리 n개의 공간을 할당한뒤, 특정 값으로 초기화
	hear.resize(n); // 이거 hear.reserve(n)으로 하면 코드 제대로 동작안함.

	for (auto&element : hear) 
		cin >> element;
	
	// 시간 절약 2 : quick sort O(nlogn)
	sort(hear.begin(), hear.end()); 

	for (int i = 0; i < m; i++) {
		string tmp;
		cin >> tmp;
		// 시간 절약 3 : binary search O(logn)
		if (binary_search(hear.begin(), hear.end(), tmp))
			res.push_back(tmp);
	}
	sort(res.begin(), res.end());

	cout << res.size() << '\n';
	for (auto&element : res)
		cout << element << '\n';

	return 0;
}