#include<iostream>
#include<stack>
#include<vector>

/*
* BOJ 1874 ���� ���� : stack library
* ���� : �־��� ������ stack push pop ������ �̿��ؼ� ���� �� �ִ��� ���� ����
* �ذ� : ������ ����ϴ� �� ��ü�� ����� ������ �ε��� ���� �� ������ٰ� ������.
		 c++ stack �޼ҵ�� push, pop, empty, top, size�� ����ϸ��
*/

using namespace std;

int main() {
	vector<int>arr;
	vector<char>pushPop;
	stack <int> s;
	bool possible = true; // can make sequence or not
	int n;
	cin >> n;

	arr.resize(n+1);
	
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	arr[0] = -1;

	int currentNum = 1;
	int idx = 1;
	int tmp;

	while (idx != (n+1)) {
		int target = arr[idx];
		if (target < arr[idx - 1]) {
			tmp = s.top();
			if (tmp != target) {
				possible = false;
				break;
			}
			s.pop();
			pushPop.push_back('-');
			idx += 1;
		}
		else {
			while (true) {
				s.push(currentNum);
				pushPop.push_back('+');
				currentNum++;
				if ((currentNum - 1) == target) break;
			}
			s.pop();
			pushPop.push_back('-');
			idx += 1;
		}
	}
	if (possible) {
		for (int i = 0; i < pushPop.size(); i++)
			cout << pushPop.at(i) << "\n";
	}
	else
		cout << "NO" << endl;

	return 0;
}