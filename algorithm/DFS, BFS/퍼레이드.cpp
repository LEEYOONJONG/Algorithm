#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int v, e;
vector<vector<int>> arr;
vector<int> degree;
int nowEdges;

void getEuler(int here) {
    for (int there = 1; there <= v; there++) {
        while (arr[here][there] > 0) {
            arr[here][there]--;
            arr[there][here]--;
            degree[here]--;
            degree[there]--;
            nowEdges--;
            getEuler(there);
        }
    }
}
int main() {
    cin >> v >> e;
    arr = vector<vector<int>>(v + 1, vector<int>(v + 1, 0));
    degree = vector<int>(v + 1, 0);
    int input1, input2;
    for (int i = 0; i < e; i++) {
        cin >> input1 >> input2;
        arr[input1][input2] = 1;
        arr[input2][input1] = 1;
        degree[input1]++;
        degree[input2]++;
    }
    nowEdges = e;
    int count = 0; // 2�� ����������� ������
    vector<int> oddIndex;
    for (int i = 1; i <= v; i++) {
        if (degree[i] % 2 == 1) {
            oddIndex.push_back(i);
            count++;
        }
    }

    if (count > 2 || count == 1) { // Ȧ�� ������ ��尡 2���� �Ѿ�ų�, 1���̸�
        cout << "NO";
    }
    else if (count == 2) { // Ȧ�� ������ ��尡 2��. ���Ϸ� �������
        int first = oddIndex[0];
        int second = oddIndex[1];
        //cout<<first<<", "<<second<<endl;
        // �׵��� �����Ѵ�.
        arr[first][second]++;
        arr[second][first]++;
        degree[first]++;
        degree[second]++;
        nowEdges++;
        getEuler(first);
        if (nowEdges == 0) cout << "YES";
        else {
            cout << "NO";
        }
    }
    else { //count==0 ���Ϸ� ȸ������
        getEuler(1); //�ƹ��ų�
        if (nowEdges == 0) cout << "YES";
        else {
            cout << "NO";
        }

    }
}