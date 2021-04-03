#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits.h>
using namespace std;

int vertex, edge;
vector<pair<int, int>> adj[20001];

vector<int> dijkstra(int src) {
	vector<int> dist(vertex+1, INT_MAX);
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src)); 

	while (!pq.empty()) {
		int cost = -pq.top().first; // 2
		int here = pq.top().second; // 2

		pq.pop();

		if (dist[here] < cost) continue; // 무시 위한
		for (int i = 0; i < adj[here].size(); i++) { //
			int there = adj[here][i].first; // 2->3
			int nextDist = cost + adj[here][i].second; // 2+4

			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}
int main() {
	cin.sync_with_stdio(NULL);
	cin >> vertex >> edge;
	int k;
	cin >> k;
	for (int i = 0; i < edge; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
	}
	vector<int> result(vertex + 1);
	result = dijkstra(k);
	for (int i = 1; i <= vertex; i++) {
		if (result[i] == INT_MAX) cout << "INF" << endl;
		else cout << result[i] << endl;
	}
}