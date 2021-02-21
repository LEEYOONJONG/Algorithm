#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void makeGraph(const vector<string>& words) {
	adj = vector<vector<int>>(26, vector<int>(26, 0));// 26x26�迭
	for (int j = 1; j < words.size(); j++) {
		int i = j - 1;
		int len = (words[i].size(), words[j].size());
		for (int k = 0; k < len; k++) {
			if (words[i][k] != words[j][k]) {
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				adj[a][b] = 1; // a->b ���� ����.
			}
		}
	}
	
}

void search() {
	//������ ���� ����, ������ ���� �ִ� ��찡 ������.
	
	for (int i = 0; i < 26; i++) {
		bool pass = false;
		for (int j = 0; j < 26; j++) {
			if (adj[j][i] == 1) { //�ϳ��� ������
				pass = true;	// �� ��
				break;
			}
		}
		if (pass == true) continue;
		else {
			// ������ ���� �־�� ��

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