#include<iostream>

using namespace std;

/*
* BOJ 11729 2*n 타일링. dp algorithm
* 문제 : input n 이 주어졌을 때, 2*n 타일을 채울 수 있는 경우의 수를 구하는 문제.
* 해결 : n=1일 때부터 n=4,5 정도일 때까지의 타일을 손으로 그려보며 규칙을 찾을 수 있다. 
		 현재의 타일을 만들기 위해서는 1. 이전 단계에서 가로1 타일을 추가 2. 전전 단계에서 가로2 타일을 추가.
		 의 과정이 필요하므로 점화식은 간단히 d(i)=d(i-1)+d(i-2)와 같이 만들 수 있다. 
*/

int cnt[1001] = { 0 };

int main() {
	int n;
	cin >> n;

	cnt[1] = 1;
	cnt[2] = 2;

	for (int i = 3; i <= n; i++) {
		cnt[i] = cnt[i - 2] + cnt[i - 1];
		cnt[i] %= 10007;
	}
	cout << cnt[n] << '\n';

	return 0;
}