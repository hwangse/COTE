#include<iostream>

using namespace std;

/*
* BOJ 6603 로또 : brute force algorithm

* 문제 : 숫자의 개수와 숫자들이 오름차순으로 주어졌을 때, 6개 숫자 조합의 가지수를 출력하기
* 해결 : dfs 알고리즘 카테고리에 있었지만 브루트포스로 가능할거같아서 그걸로 풀음.
		 중간에 브루트포스가 기억이 안나서 좀 헤메긴했지만, 재귀로 다시 짬.
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