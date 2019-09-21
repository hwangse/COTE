#include<iostream>
#include<stack>
#include<vector>

/*
* BOJ 17298 오큰수 : stack

* 문제 : 수열이 주어졌을 때, 각 숫자의 오큰수를 찾는 문제. 
		 오큰수란 해당 수보다 오른쪽에 위치하고, 해당 수보다 큰 수 중 가장 왼쪽의 숫자
* 생각 : 일단, tc 의 최대 크기가 1,000,000 이길래, 이중포문을 쓰면 안된다고는 생각.
		 글구 스택 카테고리에 있길래 스택을 써야겠다고 생각. 이때 가장 중요한 문제의 힌트는
		 "가장 왼쪽에 있는 수" -> 스택의 top()! 
* 해결 : "가장 왼쪽에 있는 수" -> 스택의 top()!  이게 문제 풀이의 핵심임.
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