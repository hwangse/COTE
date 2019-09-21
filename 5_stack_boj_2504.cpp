#include<iostream>
#include<stack>
#include<string>

/*
* BOJ 2504 ��ȣ�� �� : stack

* ���� : ��ȣ�� ���� ������ ��� ��Ģ�� �־�����, ��ȣ�� �ùٸ��� ������ ���� ���ڿ��̶�� 0�� ����ϴ� ����
* �ذ� : �˰����� ��û ������ �ƴѵ� ���� ������ ���Ƽ� ��ٷο� ��������.
		 tc �� �� �ùٸ��� ������ �� ������ ��Ÿ�ӿ����� ��� �߱淡 �ֱ׷����ߴµ�
		 ����ִ� stack�� ���� s.pop()������ ���༭ �׷���. ���־󿡼��� �̰� ������ �ȳ�����
		 �ֱ׷����� ���� �ǹ���; 
		 ��ư stack���� ���� ������ ���� �κ��� s.pop() �� s.top()��!
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