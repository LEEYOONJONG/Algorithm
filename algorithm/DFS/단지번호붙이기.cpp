#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

char arr[26][26];
bool visited[26][26];
vector<int> vc;
int n;

int dfs(int row, int col) {
	if (row < 0 || row >= n || col < 0 || col >= n) return 0;
	if (visited[row][col]) return 0;
	if (arr[row][col] == '0') return 0;

	visited[row][col] = true;
	return 1 + dfs(row, col + 1) + dfs(row, col - 1) + dfs(row - 1, col) + dfs(row + 1, col);
}

void dfsAll() {
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && arr[i][j] == '1') {
				vc.push_back(dfs(i, j));
				count++;
			}
		}
	}
	cout << count << endl;
}


int main() {
	cin >> n;
	memset(visited, false, sizeof(visited));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	dfsAll();

	sort(vc.begin(), vc.end());
	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i]<<endl;
	}
}