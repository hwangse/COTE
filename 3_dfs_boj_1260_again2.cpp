#include<iostream>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

vector<vector<int>> arr(1001,vector<int>(1001,0));

void dfs(int n, int start);
void bfs(int n, int start);

int main() {
	int n, m, start;
	cin >> n >> m >> start;

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	dfs(n,start);
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
			if (visited[i]) continue;
			if (!arr[current][i]) continue;
			visited[i] = true;
			cout << i << ' ';
			s.push(current);
			s.push(i);
			break;
		}
	}
	cout << endl;
}

void bfs(int n, int start) {
	bool visited[1001] = { false };
	queue<int> q;

	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		cout << current << ' ';
		for (int i = 1; i <= n; i++) {
			if (visited[i]) continue;
			if (!arr[current][i]) continue;
			q.push(i);
			visited[i] = true;
		}
	}
	cout << endl;
}