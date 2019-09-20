#include<iostream>
#include<array>

/*
* BOJ 2748 피보나치수 2 : dp algorithm
* 문제 : n이 주어지면 n 번째 피보나치수를 구하는 문제
* 해결 : 엄청 간단한 문젠데 왜 정답률이 낮을까 생각해서 
		 제일 큰 TC로 n=90을 넣었더니 int 로 배열을 만들면 역시나 범위초과.
		 그래서 바로 long long 으로 고쳤음.
*/

using namespace std;

int main() {
	array<long long, 91>fibo = { 0,1, };

	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	cout << fibo[n] << endl;

	return 0;
}