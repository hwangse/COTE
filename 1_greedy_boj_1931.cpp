#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>

/*
 * ���� 1931 ȸ�ǽ� ���� : ȸ�ǽ� 1���� ���� ���� ȸ�Ǹ� ������ �� �ֵ��� �����ٸ� �ϴ� ����
 
 * ���̵�� : ȸ�ǰ� �����ڸ��� �ٷ� ���� ȸ�Ǹ� �����ϸ� ��. -> ȸ�ǽð��� �󸶵��� ª�Ƶ� ok
 
 * ��üȭ : ȸ�� ������ �ð��� �������� ������������ ������ ��, ���� �ð�(���� ȸ�ǰ� ���� �ð�)�� ���س���
			���� �ð��� ���غ��� ���ų� ū ȸ�� �߿��� ���� ª�� ȸ�Ǹ� �����ϸ� ��.
 */

using namespace std;

vector<pair<int, int>> v;

int main() {
	int n;
	cin >> n;

	//(������ �ð�, ���۽ð�) ������ ���� --> sort �ϱ� ���ؼ� 
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(pair<int, int>(b, a));
	}

	sort(v.begin(), v.end());

	int currnt = 0;
	int count = 0;

	for (int i = 0; i < v.size(); i++) {
		if (v[i].second >= currnt) {
			count += 1;
			currnt = v[i].first;
		}
	}
	cout << count << '\n';

	return 0;
}