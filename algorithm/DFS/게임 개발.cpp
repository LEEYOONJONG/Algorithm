#include <iostream>
#include <deque>
#include <queue>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

int n;
int btime[501];
vector<vector<int>> building(501);
int visited[501];

int dp[501];

int dfs(int here) {
    if (dp[here] != 0) return dp[here];

    int sum = 0;
    sum += btime[here];

    int max = 0;
    for (int i = 0; i < building[here].size(); i++) {
        int temp = dfs(building[here][i]);
        if (temp > max) max = temp;
    }
    sum += max;
    dp[here] = sum;
    return sum;
}

void dfsAll() {
    for (int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        cout << dfs(i) << endl;
    }
}

int main() {

    cin >> n;
    int input;
    for (int i = 1; i <= n; i++) {
        cin >> btime[i];
        while (1) {
            cin >> input;
            if (input != -1) building[i].push_back(input);
            else break;
        }
    }
    dfsAll();
}