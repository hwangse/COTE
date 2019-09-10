#include<iostream>
#include<utility>

using namespace std;

int maxScore[100001] = { 0 };
pair<int, int> p[100001];

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		bool flag = true; //true : select 1st row ; false : select 2nd row
		cin >> n;

		for (int j = 1; j <= n; j++)
			cin >> p[j].first;
		for (int j = 1; j <= n; j++)
			cin >> p[j].second;

		maxScore[1] = p[1].first > p[1].second ? p[1].first : p[1].second;
		if (p[1].first < p[1].second)
			flag = false;

		if (n > 1) {
			int a = p[1].first + p[2].second;
			int b = p[1].second + p[2].first;
			maxScore[2] = a > b ? a : b;
			if (a > b)
				flag = false;
			else
				flag = true;
		}

		if (n >= 3) {
			for (int j = 3; j <= n; j++) {
				int tmp1,tmp2;
				if (flag) {
					tmp1 = maxScore[j - 1] + p[j].second;
					tmp2 = maxScore[j - 2] + p[j].first;
					maxScore[j] = tmp1 > tmp2 ? tmp1 : tmp2;
					if (tmp1 > tmp2)
						flag = false;
				}
				else {
					tmp1 = maxScore[j - 1] + p[j].first;
					tmp2 = maxScore[j - 2] + p[j].second;
					maxScore[j] = tmp1 > tmp2 ? tmp1 : tmp2;
					if (tmp1 > tmp2)
						flag = true;
				}
			}
		}
		cout << maxScore[n] << '\n';
	}

	return 0;
}