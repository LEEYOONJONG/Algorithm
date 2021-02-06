#include <iostream>
using namespace std;

int pre[101];
int in[101];
int n;
void tree(int start, int end) {							// (1, 3)
	int inorderMid=-1;
	for (int i = 0; i <= end; i++) {
		if (pre[start] == in[i]) {
			inorderMid == i;
			break;
		}
	}

	//tree(start, inorderMid - 1);	// (0, 2)
	//tree(inorderMid + 1, end);		// (4, 6)
	int LeftNum = (inorderMid - 1) - start;
	int RightNum = end - (inorderMid + 1);
	tree(start + 1, start + 1 + (LeftNum)-1);	// pre기준 (1, 3)
	tree(start + 1 + (LeftNum)-1 + 1, end);		// pre기준 (4, 6)
	
	cout << in[inorderMid] << ' '; //pre 기준
}

int main() {
	int c;
	
	cin >> c;
	for (int i = 0; i < c; i++) {
		
		cin >> n;
		
		for (int j = 0; j < n; j++) {
			cin >> pre[j];
		}
		for (int j = 0; j < n; j++) {
			cin >> in[j];
		}
		tree(0, n-1);

	}
}