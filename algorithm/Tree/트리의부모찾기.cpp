#include <iostream>
#include <vector>
#include <deque>
using namespace std;

bool check[100001];
vector<int> tree[100001];
int parent[100001];
void findParent(int n) {
	check[n] = 1;

	for (int i = 0; i < tree[n].size(); i++) {
		if (check[tree[n][i]] == 1) continue;
		parent[tree[n][i]] = n;
		findParent(tree[n][i]);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	findParent(1);

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}
}
/*
7
1 6
4 7
6 3
2 4
3 5
4 1
*/