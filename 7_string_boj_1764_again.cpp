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
	// �ð� ���� 1. push_back ��ſ� resize(n) -> �̸� n���� ������ �Ҵ��ѵ�, Ư�� ������ �ʱ�ȭ
	hear.resize(n); // �̰� hear.reserve(n)���� �ϸ� �ڵ� ����� ���۾���.

	for (auto&element : hear) 
		cin >> element;
	
	// �ð� ���� 2 : quick sort O(nlogn)
	sort(hear.begin(), hear.end()); 

	for (int i = 0; i < m; i++) {
		string tmp;
		cin >> tmp;
		// �ð� ���� 3 : binary search O(logn)
		if (binary_search(hear.begin(), hear.end(), tmp))
			res.push_back(tmp);
	}
	sort(res.begin(), res.end());

	cout << res.size() << '\n';
	for (auto&element : res)
		cout << element << '\n';

	return 0;
}