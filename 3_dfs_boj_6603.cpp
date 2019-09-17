#include<iostream>

using namespace std;

/*
* BOJ 6603 �ζ� : brute force algorithm

* ���� : ������ ������ ���ڵ��� ������������ �־����� ��, 6�� ���� ������ �������� ����ϱ�
* �ذ� : dfs �˰��� ī�װ��� �־����� ���Ʈ������ �����ҰŰ��Ƽ� �װɷ� Ǯ��.
		 �߰��� ���Ʈ������ ����� �ȳ��� �� ��ޱ�������, ��ͷ� �ٽ� «.
*/

int lotto[14] = { 0 };
bool visited[14] = { false };
int cnt = 0;

void brute_force(int k,int cnt,int start);

int main() {
	int k=1;

	while (k!=0) {
		cin >> k;

		if (k == 0)
			continue;

		for (int i = 1; i <= k; i++)
			cin >> lotto[i];

		for (int i = 1; i <= k; i++)
			visited[i] = false;

		cnt = 0;
		brute_force(k,cnt,1);
		cout << endl;
	}

	return 0;
}

int a[7];
void brute_force(int k,int cnt,int start) {
	if (cnt == 6) {
		for (int i = 1; i <= 6; i++)
			cout << a[i] << ' ';
		cout << endl; 
		return;
	}
	if (start > k) return;


	
	
	a[cnt+1] = lotto[start];
	brute_force(k, cnt + 1, start + 1);
	a[cnt+1] = 0;
	brute_force(k, cnt, start + 1);

}