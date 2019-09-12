#include<iostream>
#include<algorithm>

/*
* dp 알고리즘 연습 : BOJ 동전 1 

* 전형적인 dp 알고리즘 문제 (이 정도 점화식은 외워두는게 낫다)
* cost(i,k) : i번째까지의 동전을 이용하여 k를 만드는 가지 수. 라고하면
* cost(i,k) = cost(i-1,k)  (coin[i]>k 일 때)
			  cost(i-1,k) + cost(i,k-coin[i]) (coin[i]<=k 일 때) 이다.

* 위의 코드를 점화식으로 구현한 결과는 아래와 같다. 
*/

using namespace std;

int coin[101] = { 0 };
int cost[10001] = { 0 };

int main() {
	int n, k;

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> coin[i];

	sort(coin + 1, coin + 1 + n);

	cost[0] = 1;

	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			for (int j = 1; j <= k; j++) {
				if (j%coin[i] == 0)
					cost[j] = 1;
			}
		}
		else {
			for (int j = 2; j <= k; j++) {
				if (coin[i] > j)
					;
				else {
					cost[j] = cost[j] + cost[j - coin[i]];
				}
			}
		}

	}

	cout << cost[k] << '\n';

	return 0;
}