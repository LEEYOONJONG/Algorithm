#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//첫 열 기준 오름차순
bool SortSecCol1(const vector<int>& v1, const vector<int>& v2) {
	return v1[0] < v2[0];
}
//둘째 열 기준 오름차순
bool SortSecCol2(const vector<int>& v1, const vector<int>& v2) {
	return v1[1] < v2[1];
}


int main() {

	int t;
	cin >> t;


	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<vector<int>> arr(n, vector<int>(2, 0));
		for (int j = 0; j < n; j++) {
			cin >> arr[j][0] >> arr[j][1];
		}
		
		int firstLimit, secondLimit, sum=0;

		//첫 열 기준 오름차순 정렬
		sort(arr.begin(), arr.end(), SortSecCol1);
		
		int min = arr[0][1];
		int count = 1;
		for (int j = 1; j < n; j++) {
			//최소값이 발견될 때마다 카운트++
			if (arr[j][1] < min) {
				count++;
				min = arr[j][1];
			}
		}
		cout << count<<endl;

		
	}
}