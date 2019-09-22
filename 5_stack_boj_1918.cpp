#include<iostream>
#include<stack>
#include<string>
#include<vector>

/*
* BOJ 1918 후위표기식

* 문제 : 중위표기식이 주어질때, 후위표기식으로 바꾸기
* 해결 : 몇가지 규칙이 존재한다.
		 1. 피연산자는 바로 최종 계산식을 담는 finalExp로 옮긴다.
		 2. 연산자 중 '('는 바로 스택에 넣는다. (가장 낮은 우선순위)
		 3. 연산자 중 ')'는 스택에서 '('이 나올때까지 stack pop을 해주고, 괄호는 최종 문자열에 넣지X
		 4. 나머지 연산자들은, 스택에 쌓기 전에, 스택에서 본인보다 낮은 우선순위의 연산자들을 만날때까지
			그 사이의 모든 연산자들을 pop하여 final exp로 넣어준다.(이때, 본인과 같은 우선순위의 연산자도 pop 함에 주의)
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