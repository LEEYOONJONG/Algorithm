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
	if (visited[num]) return; //방문한 숫자면 X
	if (num > 9 || num < 0) return;
	visited[num] = true;
	maxarr.push_back(num); // 정답을 출력하기 위한 스택으로 활용
	
	if (maxarr.size() == inequal.size() + 1) { // 스택의 사이즈와 출력해야 할 수의 개수가 같다면
		for (int i = 0; i < maxarr.size(); i++) {	//출력
			cout << maxarr[i];
		}
		cout << endl;
		complete = true;		//더이상 연산 진행하지 않기 위해
		return;
	}

	if (inequal[index] == '<') {
		for (int i = num + 1; i < 10; i++) { // '나'보다 하나 더 큰 수부터 dfs
			maxdfs(i, index + 1);
			if (complete) break;	//출력했다면 더이상 for문 순환할 필요 없다.
		}
	}
	else {
		for (int i = num - 1; i >=0; i--) {		//'나'보다 하나 더 작은수부터 dfs
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
	
	// 초반에 큰 수가 들어가는 것이 가장 클테므로, i=9부터 dfs 진행
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