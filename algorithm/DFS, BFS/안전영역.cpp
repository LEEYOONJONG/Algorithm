#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int safeArea[101][101] = { 0, };
int visited[101][101];
int arr[101][101];

void dfs(int row, int col) {
	if (row < 0 || row >= n || col < 0 || col >= n) return;
	if (visited[row][col] == 1) return;
	if (safeArea[row][col] == 1) return; //잠긴 곳이면
	visited[row][col] = 1;
	dfs(row - 1, col);
	dfs(row + 1, col);
	dfs(row, col+1);
	dfs(row, col-1);

}

int dfsAll() {
	memset(visited, 0, sizeof(visited));
	int cnt = 0;
	queue<pair<int, int>> q;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			if (safeArea[row][col] == 0) { // 0인것만 탐색
				q.push(make_pair(row, col)); 
			}
		}
	}
	int qSize = q.size();
	for (int i = 0; i < qSize; i++) {
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		if (visited[row][col] == 1) continue;
		
		dfs(row, col);
		cnt++;
	}
	return cnt;
}

int main() {
	int maximum = -1; // 가장 높은
	int result = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			maximum = max(maximum, arr[i][j]);
		}
	}

	for (int i = 0; i <= maximum; i++) {
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < n; col++) {
				if (arr[row][col] <= i) safeArea[row][col] = 1; //잠긴다면 1
			}
		}
		
		result = max(result, dfsAll());
	}
	cout << result;
}