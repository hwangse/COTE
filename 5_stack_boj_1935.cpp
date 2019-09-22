#include<iostream>
#include<stack>
#include<string>
#include<vector>

/*
* BOJ 1935 ����ǥ��� 2

* ���� : ǥ���� ���� ǥ����� ����ϴ� ����
* �ذ� : ���� ǥ��� -> ���� ǥ����� ��ٷ���, ���� ǥ����� �ٷ� ����ϴ°�
		 ���� ����� �ʴ�. �����ڸ� ���������� stack���� �ǿ����ڸ� 2���� pop�Ͽ�
		 ������ص�, �ٽ� ���ÿ� �־��ָ� ��.

* �̻��� �� : �Ȱ��� �ڵ��ε� float�� �ϸ� Ʋ����, double�� �ϸ� �� ��...
*/

using namespace std;

int main() {
	int n;
	string exp;
	
	cin >> n;
	cin >> exp;

	vector<double> numbers(n, 0);

	for (auto &element : numbers)
		cin >> element;

	stack<double> s;

	for (int i = 0; i < exp.length(); i++) {
		char tmp = exp.at(i);
		if ('A' <= tmp && tmp <= 'Z')
			s.push(numbers[tmp-'A']);
		else  {
			double a = s.top(); s.pop();
			double b = s.top(); s.pop();
			double res;

			switch (tmp) {
				case '+': res = a + b; break;
				case '-': res = b - a; break;
				case '*': res = a * b; break;
				case '/': res = b / a; break;
			}
			s.push(res);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << s.top() << endl;


	return 0;
}