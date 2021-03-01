#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int m, n;//m이 열, n이 행
vector<vector<int>> arr;

int adjRow[4] = { -1, 0, 1, 0 };
int adjCol[4] = { 0, 1 , 0, -1 };
int maximum = 0;
void bfsAll() {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    vector<vector<int>> count(n, vector<int>(m, 0));

    // 현재 익은 토마토를 큐에 넣고, 방문완료 처리. 당일이므로 카운트는 0.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 1) {
                q.push(pair<int, int>(i, j));
                count[i][j] = 0;
                visited[i][j] = true;
            }
        }
    }
    while (!q.empty()) {
        pair<int, int> here = q.front();
        q.pop();

        //q의 이웃에 접근
        for (int i = 0; i < 4; i++) {
            if (here.first + adjRow[i] < 0 || here.first + adjRow[i] >= n || here.second + adjCol[i] < 0 || here.second + adjCol[i] >= m) continue;
            pair<int, int> there = make_pair(here.first + adjRow[i], here.second + adjCol[i]);
            //만약 방문하지 않았고, 0이라면
            if (!visited[there.first][there.second] && arr[there.first][there.second] == 0) {
                q.push(pair<int, int>(there.first, there.second));
                visited[there.first][there.second] = true;
                count[there.first][there.second] = count[here.first][here.second] + 1;
                maximum = max(maximum, count[there.first][there.second]);
            }
        }
    }

    // 0인 토마토 있나 확인
    bool unripened = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != -1 && visited[i][j] == false) { // 빈칸도 아닌데 방문 안했다면
                unripened = true;
                break;
            }
        }
        if (unripened) break;
    }
    if (unripened) cout << -1;
    else cout << maximum;

}

int main() {
    cin >> m >> n;
    arr = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    bfsAll();
}