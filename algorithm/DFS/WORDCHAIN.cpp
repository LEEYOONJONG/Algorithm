#include <iostream>
#include <deque>
#include <queue>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

int n;
string str[101];
bool check[101];
deque<string> deq;
bool isfound;

void dfs(int here) {
	if (check[here]) return;

	check[here] = true;
	
	deq.push_back(str[here]);
	if (deq.size() == n) {
		for (int i = 0; i < deq.size(); i++) {
			cout << deq[i] << ' ';
		}
		cout << endl;
		isfound = true;
		return;
	}

	char lastword = str[here][str[here].size() - 1];
	for (int i = 0; i < n; i++) {
		if (!check[i] && lastword == str[i][0]) { // 방문 안했고, here의 마지막 글자와 같다면
			dfs(i);
			if (isfound) return;
		}
	}
	
	deq.pop_back();
}

void dfsAll() {
	
	for (int i = 0; i < n; i++) { //출발
		memset(check, false, sizeof(check));
		deq.clear();
		dfs(i);
		if (isfound == true) break;
	}
	if (isfound == false) cout << "IMPOSSIBLE"<<endl;
}

int main() {
	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		
		isfound = false;
		cin >> n;
		
		for (int j = 0; j < n; j++) {
			cin >> str[j];
		}
		dfsAll();
	}
}