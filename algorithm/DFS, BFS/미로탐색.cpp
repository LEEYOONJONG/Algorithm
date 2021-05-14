#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

char arr[101][101];
bool visited[101][101];
int n, m;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	int cnt = 1;
	while (!q.empty()) {
		int qSize = q.size();
		for (int h = 0; h < qSize; h++) {
			int row = q.front().first;
			int col = q.front().second;
			q.pop();
			visited[row][col] = true;

			if (row == n - 1 && col == m - 1) { // 현재 q.top이 도착지에 도달했다면 종료.
				cout << cnt;
				return;
			}
			for (int i = 0; i < 4; i++) {
				int nrow = row + dy[i];
				int ncol = col + dx[i];
				if (arr[nrow][ncol] == '0' || visited[nrow][ncol] == true || nrow < 0 || nrow >= n || ncol < 0 || ncol >= m) continue;
				q.push(make_pair(nrow, ncol));
				visited[nrow][ncol] = true; // 요거 실수
			}

		}
		cnt++;
	}
}

int main() {
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	bfs();
}