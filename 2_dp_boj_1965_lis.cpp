#include<iostream>

using namespace std;

/*
* BOJ 11053 : LIS algorithm (최장 부분 증가수열 )

* 문제 : 주어진 n개의 수 중에서 가장 긴 부분 증가수열 구하기
* 해결 : 현재 원소보다 앞에 있는 원소 중
		 1. 현재 원소보다 작으면서
		 2. 가장 큰 부분 수열 값(len)을 갖는 원소
		 를 찾아서 +1 을 해준 뒤, 현재 원소의 len 값으로 저장해준다. 
* 주의할 점 : 마지막에 생각없이 맨 마지막 원소의 len 값을 답으로 출력해줬는데 맨 마지막 원소의
			  len값이 가장 큰 증가 부분 수열값이라는 증거가 1도 없다. 즉 모든 len 배열을 순회하면서 가장 큰 
			  값이 문제 전체의 정답이 된다. 
*/

int arr[1001] = { 0 };
int len[1001] = { 0,1, };

int main() {
	int n;
	int max_len = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 2; i <= n; i++) {
		int tempMax = 0;
		for (int j = i - 1; j >= 1; j--) {
			if (arr[j] < arr[i]) {
				if (len[j] > tempMax)
					tempMax = len[j];
			}
		}
		if (tempMax > 0)
			len[i] = tempMax + 1;
		else
			len[i] = 1;
	}

	int Max = 0;

	for (int i = 1; i <= n; i++) {
		if (len[i] > Max)
			Max = len[i];
	}
	cout << Max << '\n';

	return 0;
}