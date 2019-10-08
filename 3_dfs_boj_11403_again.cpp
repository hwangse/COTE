#include<iostream>
#include<vector>
#include<stack>

using namespace std;



bool find_route(int start, int end, int n,vector<vector<int>>& arr) {
	vector<bool> visited(n, false);
	stack<int>s;

	s.push(start);

	while (!s.empty()) {

		int current = s.top();
		s.pop();

		vector<int> tmp = arr[current];
		for (int i = 0; i < tmp.size(); i++) {
			if (!visited[i] && tmp[i]) {
				if (i == end) return true;
				visited[i] = true;
				s.push(current);
				s.push(i);// flag = true; break;
				break;
			}
		}
		//if (flag) continue;
		//if (end == s.top() && s.size()!=1) return true;
		//s.pop();
	}
	return false;
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> graph(n, vector<int>(n, 0));
	vector<vector<bool>> route(n, vector<bool>(n, false));
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> graph[i][j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			route[i][j] = find_route(i, j, n,graph);
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (route[i][j]) cout << "1 ";
			else cout << "0 ";
		}
		cout << '\n';
	}

	return 0;
}