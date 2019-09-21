#include<iostream>
#include<stack>
#include<vector>

/*
* BOJ 17298 ��ū�� : stack

* ���� : ������ �־����� ��, �� ������ ��ū���� ã�� ����. 
		 ��ū���� �ش� ������ �����ʿ� ��ġ�ϰ�, �ش� ������ ū �� �� ���� ������ ����
* ���� : �ϴ�, tc �� �ִ� ũ�Ⱑ 1,000,000 �̱淡, ���������� ���� �ȵȴٰ�� ����.
		 �۱� ���� ī�װ��� �ֱ淡 ������ ��߰ڴٰ� ����. �̶� ���� �߿��� ������ ��Ʈ��
		 "���� ���ʿ� �ִ� ��" -> ������ top()! 
* �ذ� : "���� ���ʿ� �ִ� ��" -> ������ top()!  �̰� ���� Ǯ���� �ٽ���.
*/

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> numbers(n+1,0);
	vector<int>nge(n+1,-1);
	stack<int> s;

	for (int i = 1; i <= n; i++)
		cin >> numbers[i];

	s.push(1); // push first element
	int idx = 2;

	while (!s.empty() && idx<=n) {
		int current = numbers[idx];
		while (!s.empty() && current > numbers[s.top()]) {
			nge[s.top()] = current;
			s.pop();
		}
		s.push(idx);

		idx += 1;
	}
	
	for (int i = 1; i <= n; i++)
		cout << nge[i] << ' ';
	cout << endl;

	return 0;
}