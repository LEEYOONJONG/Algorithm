#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int l;
int inita, initb;
int resa, resb;
int adjRow[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int adjCol[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void bfsAll(int row, int col) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(l, vector<bool>(l, false));
    visited[row][col] = true;
    q.push(pair<int, int>(row, col));

    vector<vector<int>> count(l, vector<int>(l, 0));
    count[row][col] = 0; //�ʱⰪ ī��Ʈ�� 0���� �ʱ�ȭ

    while (!q.empty()) {
        pair<int, int> here = q.front();
        q.pop();

        if (here.first == resa && here.second == resb) { // �������� �����ߴٸ�!
            cout << count[here.first][here.second] << endl;
            break;
        }

        for (int i = 0; i < 8; i++) {
            pair<int, int> there = make_pair(here.first + adjRow[i], here.second + adjCol[i]);
            if (there.first < 0 || there.first >= l || there.second < 0 || there.second >= l) continue;
            if (!visited[there.first][there.second]) {
                q.push(there);
                visited[there.first][there.second] = true;
                //�̿� ��忡 ���� ���ؼ� 1��ŭ�� �� ī��Ʈ.
                count[there.first][there.second] = count[here.first][here.second] + 1;
            }
        }
    }
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> l;
        cin >> inita >> initb;
        cin >> resa >> resb;
        bfsAll(inita, initb);
    }
}