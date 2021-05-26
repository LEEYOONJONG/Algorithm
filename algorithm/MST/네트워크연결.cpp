#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[10001];
bool isMerged;

typedef struct kruskal {
	int from;
	int to;
	int val;
}KS;

bool cmp(KS d1, KS d2) {
	return d1.val < d2.val;
}

int find(int u) {
	if (u == parent[u]) {
		return u;
	}
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) { // v를 u에 합치자. v의 조상은 u의 조상과 같아진다.
	isMerged = false;
	u = find(u);
	v = find(v);

	if (u == v) return; // 같은데 연결하면 사이클되므로 바로 리턴
	isMerged = true;
	parent[u] = v;
}
int main() {
	int n, m; // n은 노드 // m은 엣지

	vector<KS> edge;

	cin >> n >> m;
	// 부모를 자기 자신으로 초기화
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	//그래프 형성
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		KS newNode;
		newNode.from = a;
		newNode.to = b;
		newNode.val = c;
		edge.push_back(newNode);
	}
	// 간선 오름차순 정렬
	sort(edge.begin(), edge.end(), cmp);

	int res=0;
	for (int i = 0; i < m; i++) {
		merge(edge[i].from, edge[i].to);
		if (isMerged == true) {			
			res += edge[i].val;
		}		
	}
	cout << res;
	

	// 간선 union
}