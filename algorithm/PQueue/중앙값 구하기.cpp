#include <iostream>
#include <vector>
#include <queue>
using namespace std;



int runningMedian(int n, priority_queue<int, vector<int>, less<int>>& maxHeap,
priority_queue<int, vector<int>, greater<int>>& minHeap) {

	int ret = 0;
	if (maxHeap.size() == minHeap.size()) {
		maxHeap.push(n);
	}
	else minHeap.push(n);

	if (!minHeap.empty() && !maxHeap.empty() && maxHeap.top() > minHeap.top()) {
		int a = maxHeap.top(), b = minHeap.top();
		maxHeap.pop();
		minHeap.pop();

		minHeap.push(a);
		maxHeap.push(b);
	}
	return maxHeap.top();
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int m;
		priority_queue<int, vector<int>, less<int>> maxHeap;
		priority_queue<int, vector<int>, greater<int>> minHeap;

		cin >> m;
		cout << (m - 1) / 2 + 1<<'\n';

		for (int j = 0; j < m; j++) {
			int input;
			cin >> input;
			int tmp = runningMedian(input, maxHeap, minHeap);
			if (j%2==0) cout << tmp << ' ';
		}
		cout << '\n';

	}
}