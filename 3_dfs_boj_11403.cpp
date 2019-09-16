#include<iostream>
#include<stack>

/*
* BOJ 11403 경로찾기 : dfs algorithm

* 문제 : 그래프가 인접행렬 형태로 주어져있을때 정점들간에 경로가 있는지를 확인
* 해결 : 각각의 케이스에 대해 모두 dfs 알고리즘을 이용해서 경로가 있는지 여부를 확인하면 됨.
		 dfs 알고리즘의 핵심이라고 할 수 있는 visited 배열과 stack을 꼭 사용해줄 것!
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
// start 노드부터 goal 노드까지 경로가 있는지 없는지 확인 (dfs algorithm)
int dfs(int n,int start,int goal) {
	stack<int> s;
	bool visited[101] = { false };

	s.push(start);

	while (!s.empty()) {
		int current = s.top();
		s.pop();	//만약 모든 노드를 다 방문했다면 이 코드에 의해 스택이 비워짐

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