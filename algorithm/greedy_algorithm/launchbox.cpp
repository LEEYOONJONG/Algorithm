#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//n행 2열 벡터에서 2열을 기준으로 내림차순 정렬을 위한 함수
bool SortSecCol(const vector<int>& v1, const vector<int>& v2) {
	return v1[1] > v2[1];
}

int main() {
	int c;
	cin >> c;

	for (int i = 0; i < c; i++) {
		int n;
		cin >> n;
		vector<vector<int>> arr(n, vector<int>(2, 0));
		for (int j = 0; j < n; j++) {
			cin >> arr[j][0];
		}
		for (int j = 0; j < n; j++) {
			cin >> arr[j][1];
		}
		//2열을 기준으로 내림차순 정렬 진행.
		sort(arr.begin(), arr.end(), SortSecCol);

		int sumWarming = 0;
		int ret = -1;
		for (int j = 0; j < n; j++) {
			//초기 조건 설정
			if (j == 0) {
				ret = arr[j][0] + arr[j][1];
				sumWarming += arr[j][0];
			}

			else {
				// n-1번째 사람의 먹는 시간이 극단적으로 오래 걸리고,
				// n번째 사람의 데우는 시간과 먹는 시간이 짧을 경우까지 고려
				ret = max(ret, sumWarming + arr[j][0] + arr[j][1]);
				sumWarming += arr[j][0];
			}
		}
		cout << ret << endl;
	}
}