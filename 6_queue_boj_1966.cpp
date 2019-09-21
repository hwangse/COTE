#include<iostream>
#include<vector>

/*
* BOJ 1966 프린터 큐 : queue in c++

* 문제 : 우선순위 큐 처럼 구현하라는 문제
* 해결 : 충격적이게도 std::queue는 iteration 이 불가했다.
		 그래서 vector 공간을 크게 할당해서 queue처럼 구현했는데,
		 벡터 크기를 1000으로 할당한걸 계속 까먹고 push_back 연산을 해서
		 계속 인덱스 1000이 넘어가는 공간에 원소들이 저장되고 있었다;
		 어려운 알고리즘은 아니었지만 엄청 헤맸다.
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