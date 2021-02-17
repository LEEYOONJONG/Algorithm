#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	
	int input;
	priority_queue<int, vector<int>, less<int>> maxHeap;

	for (int i = 0; i < n; i++) {

		cin >> input;
		if (input == 0) {
			if (!maxHeap.empty()) {
				int res = maxHeap.top();
				maxHeap.pop();
				cout << res << endl;
			}
			else { //비었다면
				cout << 0 << endl;
			}
		}
		else {
			maxHeap.push(input);
		}
	}
}