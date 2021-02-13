#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
int n, m, l;

bool check(int dis) { // dis:400
	int cnt = 0;
	for (int i = 0; i < arr.size() - 1; i++) { // 휴게소간 거리 d에 dis마다 휴게소 추가 설치
		int d = arr[i + 1] - arr[i];
		int val;
		if (d / dis > 0) {
			if (d % dis == 0) val = (d / dis) - 1;
			else val = d / dis;
			cnt += val;
		}
	}
	if (cnt <= m) return true;
	else return false;
}


int main() {
	cin >> n >> m >> l;
	arr.push_back(0);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	arr.push_back(l);
	sort(arr.begin(), arr.end());

	

	int start = 0, end = l;
	int mid, res=-1;

	// 미리 답(mid) 을 가정한다.
	while (start <= end) {
		//mid = (start + end) / 2;
		mid = start + (end - start) / 2;
		if (check(mid)) { // 아직 휴게소가 부족하거나 딱 맞으면
			end = mid - 1;
			res = mid;
		}
		else start = mid + 1;
	}

	cout << res;

	return 0;
}