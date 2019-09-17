#include<iostream>
#include<stack>
#include<utility>

/*
* BOJ 10026 ������� : dfs algorithm

* ���� : RGB �÷����� �迭�� �־�������, ���� ���򳢸� ���ִ� ���� '����'�̶�� �Ѵ�. 
		 �������� �迭�� �־�����, �Ϲ� ����� ������ ����� ���� ��, ������ ���� ��� �������� ����ϴ� ����.
* �ذ� : ��� color map�� ���鼭 ���ο� ������ �����Ҷ����� dfs�� Ž���� �����ϸ� �ȴ�. Ž���� ����� ���Ҵ� 
		 visited ���� true�� �Ǿ� for �� Ž���ÿ� �׳� �Ѿ�� �ȴ�. 
		 �Ϲ� ����̶� ���� ����̶� ��ü���� �˰����� ������ �ణ �ٸ� �κ��� dfs�� ���ǹ� �κ� �ۿ� ����.
		 ���� flag �� ���� ���ǹ��� �б��Ͽ���. 

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