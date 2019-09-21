#include<iostream>
#include<stack>
#include<string>

/*
* BOJ 2504 괄호의 값 : stack

* 문제 : 괄호에 따라 일정한 계산 규칙이 주어지고, 괄호가 올바르게 닫히지 않은 문자열이라면 0을 출력하는 문제
* 해결 : 알고리즘이 엄청 어려운건 아닌데 예외 사항이 많아서 까다로운 문제였다.
		 tc 가 다 올바르게 나오는 거 같은데 런타임에러가 계속 뜨길래 왜그러나했는데
		 비어있는 stack에 대해 s.pop()연산을 해줘서 그랬다. 비주얼에서는 이게 에러가 안나던데
		 왜그런지는 나도 의문임; 
		 암튼 stack에서 가장 에러가 많은 부분은 s.pop() 과 s.top()임!
*/

using namespace std;

int main() {
	string str;
	stack<int> s;

	int res = 0;
	int calc = 1;
	int count = 0;
	bool correct = true; // correct string or not

	cin >> str;
	
	for (int i = 0; i < str.length(); i++) {
		char tmp = str.at(i);

		if (tmp == '[' || tmp == '(') s.push(tmp);

		else if (tmp == ')' || tmp==']') {
			calc = 0;
			count = 0;

			if (!s.empty()) {
				while (!s.empty()) {
					count += 1;
					if (tmp == ')') {
						if (s.top() != '(') calc += s.top();
						else break;
					}
					else {
						if (s.top() != '[') calc += s.top();
						else break;
					}
					s.pop();
				}
				if (s.empty()) correct = false;
				else
					s.pop();
			}
			if (count == 1) calc = 1;
			
			if(tmp==')') calc *= 2;
			else calc *= 3;

			s.push(calc);
		}
	}

	while (!s.empty() && correct) {
		if (s.top() == '(' || s.top() == ')' || s.top() == '[' || s.top() == ']') {
			correct = false; break;
		}

		res += s.top();
		s.pop();
	}

	if (correct) cout << res << endl;
	else cout << 0 << endl;

	return 0;
}