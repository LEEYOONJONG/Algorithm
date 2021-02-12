#include <iostream>
#include <vector>
using namespace std;

void push_heap(vector<int>& heap, int newValue) { //최소 힙
	heap.push_back(newValue);
	int idx = heap.size() - 1;
	while (idx > 0 && heap[(idx - 1) / 2] > heap[idx]) {
		swap(heap[idx], heap[(idx - 1) / 2]);
		idx = (idx - 1) / 2;
	}
}
int pop_heap(vector<int>& heap) {
	if (heap.size() == 0) return 0;
	int top = heap[0];
	heap[0] = heap.back();
	heap.pop_back();
	int here = 0;
	while (1) {
		int left = here * 2 + 1, right = here * 2 + 2;
		if (left >= heap.size()) break;
		int next = here;
		if (heap[next] > heap[left]) next = left; //왼쪽 자식이 더 작다면 next는 왼쪽자식
		if (right<heap.size() && heap[next]>heap[right]) next = right; //오른쪽 자식이 더 작다면 next는 오른쪽자식
		if (next == here) break;
		swap(heap[here], heap[next]);
		here = next;
	}

	return top;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int x;
	vector<int> heap;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) cout<<pop_heap(heap)<<'\n';
		else {
			push_heap(heap, x);
		}
	}
}