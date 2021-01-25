#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool SortSecCol(int a, int b) {
	return a>b;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	// ������������
	sort(arr.begin(), arr.end(), SortSecCol);

	// ���� ����
	long long result = 0;
	for (int i = 0; i < n; i++) {
		int tmp = arr[i] - (i+1 - 1);
		if (tmp > 0) result += tmp;
	}
	cout << result;
}