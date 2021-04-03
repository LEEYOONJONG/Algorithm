#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
vector<int> degree;
vector<vector<int>> adj;
vector<int> route;
int edgeNum = 0;

void getEuler(int here) {
    for (int there = 1; there <= n; there++) {
        while (adj[here][there] > 0) {
            adj[here][there]--;
            adj[there][here]--;
            edgeNum--;
            getEuler(there);
        }
    }
    route.push_back(here); // 가장 먼저 push되는 것은 맨 처음 노드 본인이다(여기선 1)
}

int main() {
    cin >> n;
    adj = vector<vector<int>>(n + 1, vector<int>(n + 1));
    degree = vector<int>(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    // 노드 당 차수를 계산, edge의 수도 계산
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (adj[i][j] > 0) {
                degree[i] += adj[i][j];
                degree[j] += adj[i][j];
                edgeNum += adj[i][j];
            }
        }
    }

    bool oddCount = false; // 차수가 홀수인 노드가 있느냐
    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 == 1) {
            oddCount = true;
            break;
        }
    }
    // 차수가 홀수인 노드가 있으면 얄짤없이 탈락
    if (oddCount == true) cout << "-1";
    else {
        getEuler(1); // 무엇으로 시작하든 상관없음.
        if (edgeNum != 0) cout << "-1"; // 0이 아니라는 것은, 컴포넌트가 2개 이상으로 나눠져 있다는 의미이므로 탈락
        else {
            for (int i = 0; i < route.size(); i++) {
                cout << route[i] << ' ';
            }
        }
    }
}