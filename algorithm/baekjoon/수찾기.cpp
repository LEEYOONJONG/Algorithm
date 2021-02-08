#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



void findNum(const vector<int>& arr, int tmp) {
	int start = 0;
	int end = arr.size() - 1;
	int mid;
	bool isfound = false;
	while (start <= end && !isfound) {
		mid = (start + end) / 2;
		if (arr[mid] == tmp) {
			isfound = true;
		}
		else if (tmp < arr[mid]) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	if (!isfound) cout << 0 << '\n';
	else cout << 1 << '\n';
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	
	vector<int> arr(n);
	int tmp;
	for (int i = 0; i < n; i++) {
		cin>> arr[i];
	}
	sort(arr.begin(), arr.end());

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		findNum(arr, tmp);
	}
}