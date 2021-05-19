#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <tuple>
using namespace std;

int m, n, h;
int arr[101][101][101];
int visited[101][101][101];
queue<tuple<int, int, int>> q;
int dx[6] = { 0, 0, 0, 0, 1, -1};
int dy[6] = { 0, 0, 1, -1, 0, 0};
int dz[6] = { 1, -1, 0, 0, 0, 0 };

int bfs() {

	// 모두 익었다면 = 0이 없다면 return 0
	bool zeroExist = false;
	for (int height = 0; height < h; height++) {
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < m; col++) {
				if (arr[height][row][col] == 0) {
					zeroExist = true;
					break;
				}
			}
			if (zeroExist) break;
		}
		if (zeroExist) break;
	}
	if (!zeroExist) return 0;


	int cnt = -1;
	while (!q.empty()) {
		int qSize = q.size();
		
		for (int i = 0; i < qSize; i++) {
			int height = get<0>(q.front());
			int row = get<1>(q.front());
			int col = get<2>(q.front());
			q.pop();
			visited[height][row][col] = 1;
			for (int j = 0; j < 6; j++) {
				int nHeight = height + dz[j];
				int nRow = row + dy[j];
				int nCol = col + dx[j];
				if (nHeight < 0 || nHeight >= h || nRow < 0 || nRow >= n || nCol < 0 || nCol >= m) continue; //범위 벗어난다면
				if (visited[nHeight][nRow][nCol] == 1) continue; // 방문했던 곳이라면 continue
				if (arr[nHeight][nRow][nCol] != 0) continue; // 새로 도달할 장소의 arr값은 0이어야 한다. 아니면 continue
				q.push(make_tuple(nHeight, nRow, nCol));
				visited[nHeight][nRow][nCol] = 1;
			}
		}
		cnt++;
	}
	for (int height = 0; height < h; height++) {
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < m; col++) {
				if (visited[height][row][col] == 0 && arr[height][row][col] == 0) { //안익었는데 방문하지 않았다면
					return -1;
				}
			}
		}
	}
	return cnt;
		
}

int main() {
	cin >> m >> n >> h; //m은 가로,  n은 세로
	for (int height = 0; height < h; height++) {
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < m; col++) {
				cin>>arr[height][row][col];
				if (arr[height][row][col] == 1) {
					q.push(make_tuple(height, row, col));
				}
			}
		}
	}
	cout << bfs();
}