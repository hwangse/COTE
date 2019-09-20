#include<iostream>
#include<vector>

/*
* BOJ 4344 ����� �Ѱ��� : array practice
* ���� : �� �׽�Ʈ ���̽����� ����� �Ѵ� ���л��� ������ ����ϴ� ����
* �ذ� : ��� ������ ��Ʊ⺸�ٴ� �׳� c++ vector �迭 �����Ϸ��� ������ 
		 vector �� ������ for(auto &element)�� ������ �Ź� ������ ��. 
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