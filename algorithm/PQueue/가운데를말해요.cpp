#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, less<int>> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

int runningMedian(int n) {
	
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

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		cout<<runningMedian(input)<<'\n';
	}
}

