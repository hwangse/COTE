#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

int main() {
	int testcase;
	pair<int, int>p [100001];

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		int ppl;
		cin >> ppl;
		int pass = ppl; //ÇÑ¸í¾¿ Å»¶ô

		for (int j = 1; j <= ppl; j++) {
			int a, b;
			cin >> a >> b;
			p[a].first = a; p[a].second = b;
		}

		int m = p[1].second;
		for (int j = 2; j <= ppl; j++) {
			if (p[j].second < m)
				m = p[j].second;
			else
				pass -= 1;
		}
		cout << pass << '\n';
	}

	return 0;
}