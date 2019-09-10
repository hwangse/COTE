#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>

/*
 * 백준 1931 회의실 배정 : 회의실 1개에 가장 많은 회의를 진행할 수 있도록 스케줄링 하는 문제
 
 * 아이디어 : 회의가 끝나자마자 바로 다음 회의를 시작하면 됨. -> 회의시간은 얼마든지 짧아도 ok
 
 * 구체화 : 회의 끝나는 시간을 기준으로 오름차순으로 정렬한 뒤, 기준 시간(이전 회의가 끝난 시간)을 정해놓고
			시작 시간이 기준보다 같거나 큰 회의 중에서 가장 짧은 회의를 선택하면 됨.
 */

using namespace std;

vector<pair<int, int>> v;

int main() {
	int n;
	cin >> n;

	//(끝나는 시간, 시작시간) 순으로 저장 --> sort 하기 위해서 
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(pair<int, int>(b, a));
	}

	sort(v.begin(), v.end());

	int currnt = 0;
	int count = 0;

	for (int i = 0; i < v.size(); i++) {
		if (v[i].second >= currnt) {
			count += 1;
			currnt = v[i].first;
		}
	}
	cout << count << '\n';

	return 0;
}