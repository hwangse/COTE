#include<iostream>
#include<stack>
#include<queue>

/*
* BOJ 1260 DFS BFS 

* ���� : ���� ���״�� DFS BFS Ž���� �����ϴ� ����
* �ذ� : BFS DFS ����� ������ �� �������

*/

using namespace std;

int graph[1001][1001] = { 0 };	//adjacent matrix

void dfs(int n, int start);
void bfs(int n, int start);

int main() {
	int n, m, start;
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;	//����! ����׷���ó�� �־������� ������ �׷����ε�?
		graph[b][a] = 1;
	}

	dfs(n, start);
	bfs(n, start);

	return 0;
}

void dfs(int n, int start) {
	bool visited[1001] = { false };
	stack<int> s;

	s.push(start);
	visited[start] = true;
	cout << start << ' ';

	while (!s.empty()) {
		int current = s.top();
		s.pop();
		
		for (int i = 1; i <= n; i++) {
			if (!visited[i] && graph[current][i]) {
				cout << i << ' ';
				visited[i] = true;
				s.push(current);
				s.push(i);
				break;
			}
		}

	}
	cout << endl;
}
void bfs(int n, int start) {
	bool visited[1001] = { false };
	queue<int>q;

	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int current = q.front();
		cout << current << ' ';
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (graph[current][i] && !visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
	cout << endl;
}