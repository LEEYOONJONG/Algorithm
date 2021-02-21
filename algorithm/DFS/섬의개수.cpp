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
	// cout << "row : " << row << ", col : " << col << "�� �湮��" << endl;
	// ��� üũ�Ѵ�.
	if (!visited[row][col + 1]) dfs(row, col + 1);//������
	if (!visited[row+1][col] ) dfs(row+1, col); //�Ʒ�
	if (!visited[row -1 ][col] ) dfs(row - 1, col); //��
	if (!visited[row][col-1]) dfs(row, col-1); //����
	if (!visited[row+1][col + 1]) dfs(row+1, col + 1); // �����ʾƷ�
	if (!visited[row - 1][col + 1]) dfs(row - 1, col + 1);//������ ��
	if (!visited[row + 1][col - 1]) dfs(row + 1, col - 1);//���� �Ʒ�
	if (!visited[row - 1][col - 1]) dfs(row - 1, col - 1);//���� ��
}

void dfsAll() {
	memset(visited, false, sizeof(visited));
	//���� visit���� ���� ������ ��ü dfs Ž��
	int count=0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (!visited[i][j] && arr[i][j] == 1) { // ���� �湮 ���߰�, ���� ��
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