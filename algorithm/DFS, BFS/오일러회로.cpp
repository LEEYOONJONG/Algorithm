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
    route.push_back(here); // ���� ���� push�Ǵ� ���� �� ó�� ��� �����̴�(���⼱ 1)
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
    // ��� �� ������ ���, edge�� ���� ���
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (adj[i][j] > 0) {
                degree[i] += adj[i][j];
                degree[j] += adj[i][j];
                edgeNum += adj[i][j];
            }
        }
    }

    bool oddCount = false; // ������ Ȧ���� ��尡 �ִ���
    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 == 1) {
            oddCount = true;
            break;
        }
    }
    // ������ Ȧ���� ��尡 ������ ��©���� Ż��
    if (oddCount == true) cout << "-1";
    else {
        getEuler(1); // �������� �����ϵ� �������.
        if (edgeNum != 0) cout << "-1"; // 0�� �ƴ϶�� ����, ������Ʈ�� 2�� �̻����� ������ �ִٴ� �ǹ��̹Ƿ� Ż��
        else {
            for (int i = 0; i < route.size(); i++) {
                cout << route[i] << ' ';
            }
        }
    }
}