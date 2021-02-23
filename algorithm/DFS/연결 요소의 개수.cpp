#include <iostream>
#include <deque>
#include <queue>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> arr(1001);
bool visited[1001];

void dfs(int here) { //0
    visited[here] = true;
    for (int i = 0; i < arr[here].size(); i++) {
        if (!visited[arr[here][i]]) {
            dfs(arr[here][i]);
        }
    }

}

void dfsAll() {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }
    cout << count;
}

int main() {
    memset(visited, false, sizeof(visited));

    cin >> n >> m;
    int inputA, inputB;
    for (int i = 0; i < m; i++) {
        cin >> inputA >> inputB;
        arr[inputA].push_back(inputB);
        arr[inputB].push_back(inputA);
    }
    dfsAll();
}