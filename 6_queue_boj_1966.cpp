#include<iostream>
#include<vector>

/*
* BOJ 1966 ������ ť : queue in c++

* ���� : �켱���� ť ó�� �����϶�� ����
* �ذ� : ������̰Ե� std::queue�� iteration �� �Ұ��ߴ�.
		 �׷��� vector ������ ũ�� �Ҵ��ؼ� queueó�� �����ߴµ�,
		 ���� ũ�⸦ 1000���� �Ҵ��Ѱ� ��� ��԰� push_back ������ �ؼ�
		 ��� �ε��� 1000�� �Ѿ�� ������ ���ҵ��� ����ǰ� �־���;
		 ����� �˰����� �ƴϾ����� ��û ��̴�.
*/

using namespace std;

int main() {
	int testcase;
	cin >> testcase;

	for (int k = 0; k < testcase; k++) {
		int n, target,count = 0;
		int front, back;
		vector<int>arr(1000, 0);
		
		cin >> n >> target;
		front = 0, back = n - 1;
		for (int i = 0; i < n; i++)
			cin >> arr.at(i);

		if (n > 1) {
			while (true) {
				int current = arr[front];
				bool del = true;
				for (int i = front + 1; i <= back; i++) {
					if (arr.at(i) > current) {
						del = false;
						arr.insert(arr.begin() + (back + 1), current);
						if (front == target) target = back + 1;
						front += 1; back += 1;
						break;
					}
				}
				if (del) {
					count += 1;
					if (front == target) break;
					front += 1;
				}
			}
		}

		if (n == 1)
			cout << "1\n";
		else
			cout << count << '\n';
	}

	return 0;
}