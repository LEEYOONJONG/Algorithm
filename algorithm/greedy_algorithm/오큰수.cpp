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
	//first에는 값이, second 에는 result의 index가 들어감


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	/*
	다음 원소가 더 작으면 그 값의 index와 더불어 스택에 쌓기
	다음 원소가 더 크면 그 값을 바로 result배열에 반영. 반영 후 스택의 값도 살피기
	*/



	for (int i = 0; i < n-1; i++) {
		if (arr[i] < arr[i+1]) {
			result[i] = arr[i + 1]; // i자리엔 i+1의 값이..			
			// minusStack에서 top(스택 중 최솟값이 존재)부터 arr[i+1]값과 비교하여
			// arr[i+1]보다 작으면 result에 바로 반영 후 스택에서 삭제한다.
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

	// 남은 minusStack의 자리에는 -1 집어넣기
	int restSize = minusStack.size(); 
	for (int i = 0; i < restSize; i++) {
		result[minusStack.top().second] = -1;
		minusStack.pop();
	}

	//result 배열의 맨 마지막 원소 역시 -1이다.
	result[n - 1] = -1;

	for (int i = 0; i < n; i++) {
		cout<<result[i]<<' ';
	}


	
	


}