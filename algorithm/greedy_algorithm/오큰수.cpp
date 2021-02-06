#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int arr[1000001];
int result[1000001];
int main() {
	int n;
	
	stack<pair<int, int>> minusStack;
	//first���� ����, second ���� result�� index�� ��


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	/*
	���� ���Ұ� �� ������ �� ���� index�� ���Ҿ� ���ÿ� �ױ�
	���� ���Ұ� �� ũ�� �� ���� �ٷ� result�迭�� �ݿ�. �ݿ� �� ������ ���� ���Ǳ�
	*/



	for (int i = 0; i < n-1; i++) {
		if (arr[i] < arr[i+1]) {
			result[i] = arr[i + 1]; // i�ڸ��� i+1�� ����..			
			// minusStack���� top(���� �� �ּڰ��� ����)���� arr[i+1]���� ���Ͽ�
			// arr[i+1]���� ������ result�� �ٷ� �ݿ� �� ���ÿ��� �����Ѵ�.
			int stackSize = minusStack.size();
			for (int j = 0; j < stackSize; j++) {
				if (minusStack.top().first < arr[i + 1]) {
					result[minusStack.top().second] = arr[i + 1];
					minusStack.pop();
				}
				else break;
			}
		}
		else {
			minusStack.push({ arr[i], i });
		}
	}

	// ���� minusStack�� �ڸ����� -1 ����ֱ�
	int restSize = minusStack.size(); 
	for (int i = 0; i < restSize; i++) {
		result[minusStack.top().second] = -1;
		minusStack.pop();
	}

	//result �迭�� �� ������ ���� ���� -1�̴�.
	result[n - 1] = -1;

	for (int i = 0; i < n; i++) {
		cout<<result[i]<<' ';
	}


	
	


}