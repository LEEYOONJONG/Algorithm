#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void makeGraph(const vector<string>& words) {
	adj = vector<vector<int>>(26, vector<int>(26, 0));// 26x26배열
	for (int j = 1; j < words.size(); j++) {
		int i = j - 1;
		int len = (words[i].size(), words[j].size());
		for (int k = 0; k < len; k++) {
			if (words[i][k] != words[j][k]) {
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				adj[a][b] = 1; // a->b 간선 존재.
			}
		}
	}
	
}

void search() {
	//들어오는 것이 없고, 나가는 것이 있는 경우가 시작점.
	
	for (int i = 0; i < 26; i++) {
		bool pass = false;
		for (int j = 0; j < 26; j++) {
			if (adj[j][i] == 1) { //하나라도 있으면
				pass = true;	// 안 됨
				break;
			}
		}
		if (pass == true) continue;
		else {
			// 나가는 것이 있어야 함

		}
	}
}


int main() {
	
	int c;
	cin >> c;

	for (int i = 0; i < c; i++) {
		int n;
		cin >> n;
		vector<string> words;
		string input;
		for (int j = 0; j < n; j++) {
			cin >> input;
			words.push_back(input);
		}
		adj = vector<vector<int>>(26, vector<int>(26, 0));

	}

}