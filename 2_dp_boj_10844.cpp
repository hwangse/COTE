#include<iostream>

using namespace std;

/*
* BOJ 10844 쉬운계단 수 (dp algorithm)

* 문제 : 1<= n <=100인 n (숫자의 길이 값) 이 주어질 때, n자리 수의 계단 수의 개수를 구하는 문제
* 주의할 점 : 8byte의 long long 자료형도 100자리의 정수를 담지는 못하므로 중간에 계산할 때, 
			  무조건 나머지 연산을 진행해야함. 
			  (A+B)%C = (A%C+A%B)%C 임을 이용.
* 해결 : 문제의 dp 점화식을 생각해내기는 어렵지 X. 다만 모듈러 연산이 언제필요한지 생각하는게 더 어렵.
         +) 글고 난 바보같이 배열연산 관련해서 잘못생각한게 한가지 있어서 계속 틀림;

*/

long long stair[101] = { 0 };
long long number[10] = { 0 };

#define BIG_NUM 1000000000

int main() {
	int n;

	cin >> n;

	stair[1] = 9;
	for (int i = 1; i < 10; i++) number[i] = 1;

	for (int i = 2; i <= n; i++) {
		long long tmp = 0;

		for (int j = 0; j < 10; j++) {
			if (j == 0 || j == 9) tmp += (number[j]);
			else tmp += ((number[j] * 2));
		}

		stair[i] = tmp;

		long long tmp_number[10] = { 0 };

		for (int j = 0; j < 10; j++) {
			if (j == 0)
				tmp_number[j + 1] += (number[j] % BIG_NUM);
			else if (j == 9)
				tmp_number[j - 1] += (number[j] % BIG_NUM);
			else {
				tmp_number[j + 1] += (number[j] % BIG_NUM);
				tmp_number[j - 1] += (number[j] % BIG_NUM);
			}
		}

		for (int j = 0; j < 10; j++)
			number[j] = tmp_number[j];

	}

	cout << stair[n] % BIG_NUM << '\n';

	return 0;
}