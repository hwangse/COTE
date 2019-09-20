#include<iostream>
#include<vector>

/*
* BOJ 4344 평균은 넘겠지 : array practice
* 문제 : 각 테스트 케이스마다 평균이 넘는 대학생의 비율을 출력하는 문제
* 해결 : 사실 문제가 어렵기보다는 그냥 c++ vector 배열 연습하려고 고른문제 
		 vector 쓸 때마다 for(auto &element)의 편리성을 매번 느끼는 중. 
*/

using namespace std;

int main() {
	vector<int> v;
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		int num;
		float avg=0;
		cin >> num;
		v.resize(num);

		for (auto& element : v) {
			cin >> element;
			avg += element;
		}
		avg /= num;

		float rate = 0;

		for (auto &element : v) {
			if (element > avg) rate += 1;
		}

		cout << fixed;
		cout.precision(3);
		cout << (rate / num) * 100 << "%" << endl;

	}

	return 0;
}