#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

int n, m;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int minimum = 987654321;
vector<vector<int>> arr;
vector<pair<int, int>> virus;
vector<vector<bool>> visited;
vector<int> selectedVirus;

bool check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) continue; //벽이면 통과
            if (visited[i][j] == false) return false; // 벽이 아닌데 방문 안했으면 false 리턴
        }
    }
    return true;
}

void bfs() {

    queue<pair<int, int>> q;
    //    cout<<"-->"<< selectedVirus.size()<<endl;
    for (int i = 0; i < selectedVirus.size(); i++) {
        int row = virus[selectedVirus[i]].first;
        int col = virus[selectedVirus[i]].second;
        //        cout<<row<<", "<<col<<endl;

        q.push(make_pair(row, col));
        visited[row][col] = true;
    }
    int cnt = 0;
    while (!q.empty()) {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int j = 0; j < 4; j++) {
                int nrow = row + dy[j];
                int ncol = col + dx[j];
                if (0 <= nrow && 0 <= ncol && nrow < n && ncol < n) {
                    if (!visited[nrow][ncol] && arr[nrow][ncol] != 1) {
                        visited[nrow][ncol] = true;
                        q.push(make_pair(nrow, ncol));
                    }
                }
            }
        }
        if (q.size() != 0) cnt++;
    }
    if (check()) minimum = min(minimum, cnt);

}

bool selected[11];
void dfs(int idx, int cnt) {
    if (cnt == m) {
        // bfs 드가자

        selectedVirus.clear();
        for (int i = 0; i < virus.size(); i++) {
            if (selected[i] == true) {
                selectedVirus.push_back(i);
            }
        }
        visited = vector<vector<bool>>(n, vector<bool>(n, false));
        bfs();
        return;
    }
    for (int i = idx; i < virus.size(); i++) {
        if (selected[i] == true) continue;
        selected[i] = true;
        dfs(i, cnt + 1);
        selected[i] = false;
    }

}

int main() {
    cin >> n >> m;
    arr = vector<vector<int>>(n, vector<int>(n, 0));
    visited = vector<vector<bool>>(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                virus.push_back(make_pair(i, j));
            }
        }
    }
    dfs(0, 0);
    if (minimum == 987654321) cout << -1;
    else   cout << minimum;
}