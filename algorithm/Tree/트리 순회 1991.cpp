#include <iostream>
#include <vector>
using namespace std;

int n;
void preOrder(vector<vector<char>> arr, int index) {
	if (arr[index][0] != '.') cout << arr[index][0];
	else return;

	int leftIdx = -1, rightIdx = -1;

	//왼쪽 자식이 .이 아니라면
	if (arr[index][1] != '.') {
		for (int i = 0; i < n; i++) {
			if (arr[index][1] == arr[i][0]) {
				leftIdx = i;
				break;
			}
		}
		preOrder(arr, leftIdx);
	}

	//오른쪽 자식이 .이 아니라면
	if (arr[index][2] != '.') {
		for (int i = 0; i < n; i++) {
			if (arr[index][2] == arr[i][0]) {
				rightIdx = i;
				break;
			}
		}
		preOrder(arr, rightIdx);
	}

}
void inOrder(vector<vector<char>> arr, int index) {
	if (arr[index][0] == '.') return;

	int leftIdx = -1, rightIdx = -1;

	//왼쪽 자식이 .이 아니라면
	if (arr[index][1] != '.') {
		for (int i = 0; i < n; i++) {
			if (arr[index][1] == arr[i][0]) {
				leftIdx = i;
				break;
			}
		}
		inOrder(arr, leftIdx);
	}
	cout << arr[index][0];
	//오른쪽 자식이 .이 아니라면
	if (arr[index][2] != '.') {
		for (int i = 0; i < n; i++) {
			if (arr[index][2] == arr[i][0]) {
				rightIdx = i;
				break;
			}
		}
		inOrder(arr, rightIdx);
	}

}

void postOrder(vector<vector<char>> arr, int index) {
	if (arr[index][0] == '.') return;

	int leftIdx=-1, rightIdx=-1;

	//왼쪽 자식이 .이 아니라면
	if (arr[index][1] != '.') {
		for (int i = 0; i < n; i++) {
			if (arr[index][1] == arr[i][0]) {
				leftIdx = i;
				break;
			}
		}
		postOrder(arr, leftIdx);
	}

	//오른쪽 자식이 .이 아니라면
	if (arr[index][2] != '.') {
		for (int i = 0; i < n; i++) {
			if (arr[index][2] == arr[i][0]) {
				rightIdx = i;
				break;
			}
		}
		postOrder(arr, rightIdx);
	}
	cout << arr[index][0];
}
int main() {
	
	
	cin >> n;
	vector<vector<char>> arr(n, vector<char>(3, 0));

	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	preOrder(arr, 0);
	cout << endl;
	inOrder(arr, 0);
	cout << endl;
	postOrder(arr, 0);
}