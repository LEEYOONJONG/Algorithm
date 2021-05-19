#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<pair<int, int>> adj[20001]; // ���� ����Ʈ
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(NULL);
	int v, e, k;
	cin >> v >> e;
	cin >> k; // ������
	for (int i = 0; i < e; i++) {
		int input1, input2, input3;
		cin >> input1 >> input2 >> input3;
		adj[input1].push_back(make_pair(input2, input3));
	}

	//  dist[1] ~ dist[v]. dist�� �ش� �ε��������� �Ÿ�
	vector<int> dist(v + 1, 987654321);
	dist[k] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, k));
	while (!pq.empty()) {
		int cost = -pq.top().first; // pq.top().first���� ������ ����Ǿ� ����
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue; // cost�� �� ũ�� ���͵�����.
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first; // there�� here�� ������ ���
			int nextDist = cost + adj[here][i].second;
			if (dist[there] > nextDist) { // ���ο� �Ÿ� nextDist�� ������ dist[there]���� �۴ٸ� ������Ʈ.
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (dist[i] == 987654321) cout << "INF" << '\n';

		else cout << dist[i] << '\n';
	}
}