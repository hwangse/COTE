#include<iostream>
#include<stack>
#include<utility>

/*
* BOJ 10026 적녹색약 : dfs algorithm

* 문제 : RGB 컬러값이 배열로 주어졌을때, 같은 색깔끼리 모여있는 것을 '구역'이라고 한다. 
		 문제에서 배열이 주어지고, 일반 사람과 색약인 사람이 봤을 때, 구역이 각각 몇개로 나뉘는지 출력하는 문제.
* 해결 : 모든 color map을 돌면서 새로운 구역을 마주할때마다 dfs로 탐색을 시작하면 된다. 탐색이 진행된 원소는 
		 visited 값이 true가 되어 for 문 탐색시에 그냥 넘어가게 된다. 
		 일반 사람이랑 색약 사람이랑 전체적인 알고리즘은 같으나 약간 다른 부분은 dfs시 조건문 부분 밖에 없다.
		 따라서 flag 를 통해 조건문을 분기하였다. 

*/

using namespace std;

char color[101][101] = { 0 };

//flag = false : normal person, flag = true : color blind
int countSection(int n, bool flag);

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> color[i][j];
		}
	}

	cout << countSection(n, false) << ' ' <<countSection(n, true) << endl;

	return 0;
}

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int countSection(int n, bool flag) {
	bool visited[101][101] = { false };
	stack<pair<int, int>> s;
	int section_num = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j]) continue;

			//start bfs algorithm
			section_num += 1;
			s.push(make_pair(i, j));
			visited[i][j] = true;
			char start = color[i][j];

			while (!s.empty()) {
				pair<int, int> current = s.top();
				s.pop();

				for (int k = 0; k < 4; k++) {
					int nx = current.second + dx[k];
					int ny = current.first + dy[k];

					if (!flag) {
						if (1 <= nx && nx <= n && 1 <= ny && ny <= n && !visited[ny][nx] && color[ny][nx] == start) {
							visited[ny][nx] = true;
							s.push(make_pair(current.first, current.second));
							s.push(make_pair(ny, nx));
							break;
						}
					}
					else {
						if (1 <= nx && nx <= n && 1 <= ny && ny <= n && !visited[ny][nx]) {
							if ((start == 'R' && (color[ny][nx] == 'G' || color[ny][nx] == start)) || (start == 'G' && (color[ny][nx] == 'R' || color[ny][nx] == start)) || (start=='B' && color[ny][nx]==start)) {
								visited[ny][nx] = true;
								s.push(make_pair(current.first, current.second));
								s.push(make_pair(ny, nx));
								break;
							}
						}
					}
				}
			}
		}
	}

	return section_num;
}