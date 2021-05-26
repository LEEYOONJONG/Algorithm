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

void merge(int u, int v) { // v�� u�� ��ġ��. v�� ������ u�� ����� ��������.
	isMerged = false;
	u = find(u);
	v = find(v);

	if (u == v) return; // ������ �����ϸ� ����Ŭ�ǹǷ� �ٷ� ����
	isMerged = true;
	parent[u] = v;
}
int main() {
	int n, m; // n�� ��� // m�� ����

	vector<KS> edge;

	cin >> n >> m;
	// �θ� �ڱ� �ڽ����� �ʱ�ȭ
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	//�׷��� ����
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		KS newNode;
		newNode.from = a;
		newNode.to = b;
		newNode.val = c;
		edge.push_back(newNode);
	}
	// ���� �������� ����
	sort(edge.begin(), edge.end(), cmp);

	int res=0;
	for (int i = 0; i < m; i++) {
		merge(edge[i].from, edge[i].to);
		if (isMerged == true) {			
			res += edge[i].val;
		}		
	}
	cout << res;
	

	// ���� union
}