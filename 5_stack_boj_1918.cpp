#include<iostream>
#include<stack>
#include<string>
#include<vector>

/*
* BOJ 1918 ����ǥ���

* ���� : ����ǥ����� �־�����, ����ǥ������� �ٲٱ�
* �ذ� : ��� ��Ģ�� �����Ѵ�.
		 1. �ǿ����ڴ� �ٷ� ���� ������ ��� finalExp�� �ű��.
		 2. ������ �� '('�� �ٷ� ���ÿ� �ִ´�. (���� ���� �켱����)
		 3. ������ �� ')'�� ���ÿ��� '('�� ���ö����� stack pop�� ���ְ�, ��ȣ�� ���� ���ڿ��� ����X
		 4. ������ �����ڵ���, ���ÿ� �ױ� ����, ���ÿ��� ���κ��� ���� �켱������ �����ڵ��� ����������
			�� ������ ��� �����ڵ��� pop�Ͽ� final exp�� �־��ش�.(�̶�, ���ΰ� ���� �켱������ �����ڵ� pop �Կ� ����)
*/

using namespace std;

int get_priority(char op) {
	switch (op) {
	case '(': return 0;
	case '+' : 
	case '-': return 1;
	case '*' : 
	case '/': return 2;
	}
}

int main() {
	string exp;
	vector<char>finalExp;
	stack<char> op;
	cin >> exp;

	for (int i = 0; i < exp.length(); i++) {
		char current = exp.at(i);
		
		if ('A' <= current && current <= 'Z')
			finalExp.push_back(current);
		else {
			if (current == '(') op.push(current);
			else if (current == ')') {
				while (!op.empty() && op.top() != '(') {
					finalExp.push_back(op.top());
					op.pop();
				}
				op.pop();
			}
			else {
				while (!op.empty() && get_priority(current) <= get_priority(op.top())) {
					finalExp.push_back(op.top());
					op.pop();
				}
				op.push(current);
			}
		}
	}
	while (!op.empty()) {
		finalExp.push_back(op.top());
		op.pop();
	}

	for (auto&element : finalExp)
		cout << element;
	cout << endl;

	return 0;
}