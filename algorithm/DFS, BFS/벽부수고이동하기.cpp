#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <tuple>
using namespace std;

int n, m;
char arr[1001][1001];
bool visited[1001][1001];
bool crushArr[1001][1001];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int bfsAll() {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), 0));
	visited[0][0] = 1;
	crushArr[0][0] = 0;
	int cnt = 1;
	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int row = q.front().first.first;
			int col = q.front().first.second;
			int crushed = q.front().second;
			cout << row << ", " << col <<" : "<<crushed<<", cnt: "<<cnt<< endl;
			if (row == n-1 && col == m-1) return cnt;
			q.pop();
			/*visited[row][col] = 1;*/

			for (int j = 0; j < 4; j++) {
				int nRow = row + dy[j];
				int nCol = col + dx[j];
				
				if (nRow == 2 && nCol == 3 && crushed == 0) cout << "here5" << endl;

				if (nRow < 0 || nRow >= n || nCol < 0 || nCol >= m) continue;
				if (visited[nRow][nCol] == 1) {
					if (crushed == 1) continue; // 방문했던곳이고, 이미 뚫은적있다면
					else {
						
						if (crushArr[nRow][nCol] != crushArr[row][col]) {
							if (nRow == 2 && nCol == 3 && crushed == 0) cout << "here3" << endl;

						}
						else {
							if (nRow == 2 && nCol == 3 && crushed == 0) cout << "here4" << endl;
							continue;
						}
					}
				}
				if (nRow == 2 && nCol == 3 && crushed == 0) cout << "here" << endl;
				if (arr[nRow][nCol] == '1'){
					if (nRow == 2 && nCol == 3 && crushed == 0) cout << "here1" << endl;
					if (crushed == 0) { //벽이긴 한데 아직 부순적 없다면
						q.push(make_pair(make_pair(nRow, nCol), 1));
						visited[nRow][nCol] = 1;
						crushArr[nRow][nCol] = 1;
					}
					else continue;
				}
				else { // arr이 0이면
					if (nRow == 2 && nCol == 3 && crushed == 0) cout << "here2" << endl;
					q.push(make_pair(make_pair(nRow, nCol), crushed));
					visited[nRow][nCol] = 1;
					crushArr[nRow][nCol] = crushArr[row][col];
				}
			}
		}
		cnt++;
	}
	return -1;

}



int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	cout<<bfsAll();
}