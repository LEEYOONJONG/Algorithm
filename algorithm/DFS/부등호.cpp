#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <string.h>
using namespace std;

vector<char> inequal;
bool visited[11];
deque<int> maxarr;
deque<int> minarr;
bool complete = false;
bool completemin = false;

void maxdfs(int num, int index) { // 9, 0
	if (visited[num]) return; //�湮�� ���ڸ� X
	if (num > 9 || num < 0) return;
	visited[num] = true;
	maxarr.push_back(num); // ������ ����ϱ� ���� �������� Ȱ��
	
	if (maxarr.size() == inequal.size() + 1) { // ������ ������� ����ؾ� �� ���� ������ ���ٸ�
		for (int i = 0; i < maxarr.size(); i++) {	//���
			cout << maxarr[i];
		}
		cout << endl;
		complete = true;		//���̻� ���� �������� �ʱ� ����
		return;
	}

	if (inequal[index] == '<') {
		for (int i = num + 1; i < 10; i++) { // '��'���� �ϳ� �� ū ������ dfs
			maxdfs(i, index + 1);
			if (complete) break;	//����ߴٸ� ���̻� for�� ��ȯ�� �ʿ� ����.
		}
	}
	else {
		for (int i = num - 1; i >=0; i--) {		//'��'���� �ϳ� �� ���������� dfs
			maxdfs(i, index + 1);
			if (complete) break;
		}
	}
	visited[maxarr.back()] = false;
	maxarr.pop_back();
}

void mindfs(int num, int index) {
	if (visited[num]) return;
	if (num > 9 || num < 0) return;
	visited[num] = true;
	minarr.push_back(num);
	if (minarr.size() == inequal.size() + 1) {
		for (int i = 0; i < minarr.size(); i++) {
			cout << minarr[i];
		}
		cout << endl;
		completemin = true;
		return;
	}
	if (inequal[index] == '<') {
		for (int i = num + 1; i < 10; i++) {
			mindfs(i, index + 1);
			if (completemin) break;
		}
	}
	else {
		for (int i = num - 1; i >= 0; i--) {
			mindfs(i, index + 1);
			if (completemin) break;
		}
	}
	visited[minarr.back()] = false;
	minarr.pop_back();
}
void maxdfsAll() {
	
	// �ʹݿ� ū ���� ���� ���� ���� Ŭ�׹Ƿ�, i=9���� dfs ����
	for (int i = 9; i >= 0; i--) {
		memset(visited, false, sizeof(visited));
		maxdfs(i, 0);
		if (complete) break;
	}
}
void mindfsAll() {
	for (int i = 0; i <= 9; i++) {
		memset(visited, false, sizeof(visited));
		mindfs(i, 0);
		if (completemin) break;
	}
}
int main() {
	int k;
	cin >> k;
	char input;
	for (int i = 0; i < k; i++) {
		cin >> input;
		inequal.push_back(input);
	}

	maxdfsAll();
	mindfsAll();
}