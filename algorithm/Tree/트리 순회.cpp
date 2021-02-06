#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> inOrder;
vector<int> postOrder;



void pre( int inStart, int inEnd, int postStart, int postEnd) {
	if (inStart > inEnd || postStart > postEnd) return;  // 4,5 3,4
	cout << postOrder[postEnd] << ' ';
	
	
	// Postorder의 맨 뒤 원소는 inorder의 몇번째 index인지
	int rootIndex = find(inOrder.begin(), inOrder.end(), postOrder[postEnd]) - inOrder.begin(); // 4
	
	

	//왼쪽 작업
	//if (inEnd - inStart  != 0)
		pre( inStart, rootIndex - 1, postStart, postStart+ ((rootIndex-1) - inStart)); // 4, 3 3, 3
	//오른쪽 작업
	//if (postEnd - postStart  != 0)
		pre( rootIndex+1, inEnd, (postEnd-1) - (inEnd - (rootIndex+1)), postEnd-1); // 5, 5  4, 3
	return;

}

int main() {

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		inOrder.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		postOrder.push_back(tmp);
	}

	pre( 0, n-1, 0, n-1);

	return 0;
}

/*
6
4 2 5 1 3 7
4 5 2 7 3 1

*/