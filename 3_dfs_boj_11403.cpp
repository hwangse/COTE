#include<iostream>
#include<stack>

/*
* BOJ 11403 ���ã�� : dfs algorithm

* ���� : �׷����� ������� ���·� �־��������� �����鰣�� ��ΰ� �ִ����� Ȯ��
* �ذ� : ������ ���̽��� ���� ��� dfs �˰����� �̿��ؼ� ��ΰ� �ִ��� ���θ� Ȯ���ϸ� ��.
		 dfs �˰����� �ٽ��̶�� �� �� �ִ� visited �迭�� stack�� �� ������� ��!
*/

using namespace std;

int graph[101][101] = { 0 };
int routeFind[101][101] = { 0 };

int dfs(int n,int start,int goal);

int main() {	
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dfs(n, i, j))
				routeFind[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << routeFind[i][j]<<' ';
		cout << endl;
	}

	return 0;
}
// start ������ goal ������ ��ΰ� �ִ��� ������ Ȯ�� (dfs algorithm)
int dfs(int n,int start,int goal) {
	stack<int> s;
	bool visited[101] = { false };

	s.push(start);

	while (!s.empty()) {
		int current = s.top();
		s.pop();	//���� ��� ��带 �� �湮�ߴٸ� �� �ڵ忡 ���� ������ �����

		for (int i = 1; i <= n; i++) {
			if (!visited[i] && graph[current][i]) {
				if (i == goal) return 1;
				visited[i] = true;
				s.push(current);
				s.push(i);
				break;
			}
		}

	}
	return 0;
}