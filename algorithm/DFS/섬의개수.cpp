#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int arr[51][51];
bool visited[51][51];
int w, h;

void dfs(int row, int col) {
	if (arr[row][col] == 0) return;
	if (row >= h || col >= w || row<0 || col<0) return;
	visited[row][col] = true;
	// cout << "row : " << row << ", col : " << col << "을 방문함" << endl;
	// 경로 체크한다.
	if (!visited[row][col + 1]) dfs(row, col + 1);//오른쪽
	if (!visited[row+1][col] ) dfs(row+1, col); //아래
	if (!visited[row -1 ][col] ) dfs(row - 1, col); //위
	if (!visited[row][col-1]) dfs(row, col-1); //왼쪽
	if (!visited[row+1][col + 1]) dfs(row+1, col + 1); // 오른쪽아래
	if (!visited[row - 1][col + 1]) dfs(row - 1, col + 1);//오른쪽 위
	if (!visited[row + 1][col - 1]) dfs(row + 1, col - 1);//왼쪽 아래
	if (!visited[row - 1][col - 1]) dfs(row - 1, col - 1);//왼쪽 위
}

void dfsAll() {
	memset(visited, false, sizeof(visited));
	//아직 visit하지 않은 공간을 전체 dfs 탐색
	int count=0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (!visited[i][j] && arr[i][j] == 1) { // 아직 방문 안했고, 땅일 때
				dfs(i, j);
				count++;
			}
		}
	}
	cout << count << endl;
}

int main() {
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
			}
		}
		dfsAll();
	}
}