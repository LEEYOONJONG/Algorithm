#include <iostream>
#include <deque>
#include <queue>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<string> words;
vector<int> indegree;
vector<int> outdegree;
vector<string> graph[26][26];
int adj[26][26]; //�������
void getEulerCircuit(int here, vector<int>& circuit) {
	for (int there = 0; there < 26; there++) {
		while (adj[here][there] > 0) {
			adj[here][there]--;
			getEulerCircuit(there, circuit);
		}
	}
	circuit.push_back(here);
}
vector<int> getEuler(){
	vector<int> circuit;
	//����� ���
	for (int i = 0; i < 26; i++) {
		if (outdegree[i] == indegree[i] + 1) {
			getEulerCircuit(i, circuit);
			return circuit;
		}
	}
	//��Ŷ��.
	for (int i = 0; i < 26; i++) { //���� �ʿ�?
		if (outdegree[i]) {		//���� �ʿ�?
			getEulerCircuit(i, circuit);
			return circuit;
		}
	}
}
bool checkEuler() {
	int plus1 = 0, minus1 = 0;
	for (int i = 0; i < 26; i++) {
		int delta = outdegree[i] - indegree[i];
		if (delta < -1 || delta>1) return false;
		if (delta == 1) plus1++;
		if (delta == -1)minus1++;
	}
	return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}
int main() {
	// (int)'a'; // 97
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		words = vector<string>(); //�ʱ�ȭ
		indegree = vector<int>(26,0); //�ʱ�ȭ
		outdegree = vector<int>(26,0); //�ʱ�ȭ
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++) graph[i][j].clear();
		memset(adj, 0, sizeof(adj));


		string input;
		for (int j = 0; j < n; j++) {
			cin >> input;
			words.push_back(input);
			int front = (int)input[0] - 'a';
			int back = (int)input[input.size() - 1] - 'a';
			graph[front][back].push_back(input);
			adj[front][back]++;
			outdegree[front]++;
			indegree[back]++;
		}
		if (!checkEuler()) cout << "IMPOSSIBLE" << endl;
		else {
			vector<int> result = getEuler();
			if (result.size() != words.size() + 1) cout << "IMPOSSIBLE" << endl;
			else {
				reverse(result.begin(), result.end());
				for (int j = 1; j < result.size(); j++) {
					int a = result[j - 1], b = result[j];
					cout << graph[a][b].back() << ' ';
					graph[a][b].pop_back();
				}
			}
		}
	}
}