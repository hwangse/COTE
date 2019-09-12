#include<iostream>
#include<algorithm>

/*
* dp �˰��� ���� : BOJ ���� 1 

* �������� dp �˰��� ���� (�� ���� ��ȭ���� �ܿ��δ°� ����)
* cost(i,k) : i��°������ ������ �̿��Ͽ� k�� ����� ���� ��. ����ϸ�
* cost(i,k) = cost(i-1,k)  (coin[i]>k �� ��)
			  cost(i-1,k) + cost(i,k-coin[i]) (coin[i]<=k �� ��) �̴�.

* ���� �ڵ带 ��ȭ������ ������ ����� �Ʒ��� ����. 
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