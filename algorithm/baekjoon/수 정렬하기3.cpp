#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void quick_sort(vector<int>& list, int left, int right) {
	if (left >= right) return;
	int pivot = left;
	int start = left + 1;
	int end = right;

	while (start <= end) {
		while (list[pivot] >= list[start] && start <= right) start++;
		while (list[pivot] <= list[end] && end > left) end--;
		if (start > end) swap(list[pivot], list[end]);
		else swap(list[start], list[end]);
	}
	quick_sort(list, left, end - 1);
	quick_sort(list, end + 1, right);
}

int cache[10001];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> arr;
	int vectorCount = 0;
	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (cache[tmp] == 0) {
			cache[tmp]++; // tmp의 개수 카운팅
			arr.push_back(tmp);
			vectorCount++;
		}
		else {
			cache[tmp]++;
		}
	}

	quick_sort(arr, 0, vectorCount - 1);
	for (int i = 0; i < vectorCount; i++) { // arr[i]를 X번 출력해야 함
		for (int j=0; j<cache[arr[i]]; j++)
			cout << arr[i]<<'\n';
	}
}