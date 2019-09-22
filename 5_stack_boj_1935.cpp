#include<iostream>
#include<stack>
#include<string>
#include<vector>

/*
* BOJ 1935 후위표기식 2

* 문제 : 표현된 후위 표기식을 계산하는 문제
* 해결 : 중위 표기식 -> 후위 표기식이 까다롭지, 후위 표기식을 바로 계산하는건
		 별로 어렵지 않다. 연산자를 만날때마다 stack에서 피연산자를 2개씩 pop하여
		 계산해준뒤, 다시 스택에 넣어주면 됨.

* 이상한 점 : 똑같은 코드인데 float로 하면 틀리고, double로 하면 잘 됨...
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