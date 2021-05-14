#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;


int main() {
	int c;
	cin >> c; // 3
	

	for (int i = 0; i < c; i++) {
		int n; // 5
		stack<int> arr[4];
		cin >> n;
		for (int pan = 0; pan < 4; pan++) {
			int num;
			cin >> num; // 2
			for (int j = 0; j < num; j++) {
				int tmp;
				cin >> tmp;
				arr[pan].push(tmp); //  5 4
			}
		}
		// bfs

		if (arr[0].size() == 0 && arr[1].size() == 0 && arr[2].size() == 0) {
			cout << 0 << endl;
			continue;
		}
		for (int begin = 0; begin < 4; begin++) {
			queue<int> q;
			q.push(begin);




		}



	}

}