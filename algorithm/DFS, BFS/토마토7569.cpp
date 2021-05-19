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

	// ��� �;��ٸ� = 0�� ���ٸ� return 0
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
				if (nHeight < 0 || nHeight >= h || nRow < 0 || nRow >= n || nCol < 0 || nCol >= m) continue; //���� ����ٸ�
				if (visited[nHeight][nRow][nCol] == 1) continue; // �湮�ߴ� ���̶�� continue
				if (arr[nHeight][nRow][nCol] != 0) continue; // ���� ������ ����� arr���� 0�̾�� �Ѵ�. �ƴϸ� continue
				q.push(make_tuple(nHeight, nRow, nCol));
				visited[nHeight][nRow][nCol] = 1;
			}
		}
		cnt++;
	}
	for (int height = 0; height < h; height++) {
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < m; col++) {
				if (visited[height][row][col] == 0 && arr[height][row][col] == 0) { //���;��µ� �湮���� �ʾҴٸ�
					return -1;
				}
			}
		}
	}
	return cnt;
		
}

int main() {
	cin >> m >> n >> h; //m�� ����,  n�� ����
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