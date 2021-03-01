#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int m, n;//m�� ��, n�� ��
vector<vector<int>> arr;

int adjRow[4] = { -1, 0, 1, 0 };
int adjCol[4] = { 0, 1 , 0, -1 };
int maximum = 0;
void bfsAll() {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    vector<vector<int>> count(n, vector<int>(m, 0));

    // ���� ���� �丶�並 ť�� �ְ�, �湮�Ϸ� ó��. �����̹Ƿ� ī��Ʈ�� 0.
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

        //q�� �̿��� ����
        for (int i = 0; i < 4; i++) {
            if (here.first + adjRow[i] < 0 || here.first + adjRow[i] >= n || here.second + adjCol[i] < 0 || here.second + adjCol[i] >= m) continue;
            pair<int, int> there = make_pair(here.first + adjRow[i], here.second + adjCol[i]);
            //���� �湮���� �ʾҰ�, 0�̶��
            if (!visited[there.first][there.second] && arr[there.first][there.second] == 0) {
                q.push(pair<int, int>(there.first, there.second));
                visited[there.first][there.second] = true;
                count[there.first][there.second] = count[here.first][here.second] + 1;
                maximum = max(maximum, count[there.first][there.second]);
            }
        }
    }

    // 0�� �丶�� �ֳ� Ȯ��
    bool unripened = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != -1 && visited[i][j] == false) { // ��ĭ�� �ƴѵ� �湮 ���ߴٸ�
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