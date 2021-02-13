#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> arr;
int n, m, l;

bool check(int dis) { // dis:400
	int cnt = 0;
	for (int i = 0; i < arr.size() - 1; i++) { // �ްԼҰ� �Ÿ� d�� dis���� �ްԼ� �߰� ��ġ
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

	// �̸� ��(mid) �� �����Ѵ�.
	while (start <= end) {
		//mid = (start + end) / 2;
		mid = start + (end - start) / 2;
		if (check(mid)) { // ���� �ްԼҰ� �����ϰų� �� ������
			end = mid - 1;
			res = mid;
		}
		else start = mid + 1;
	}

	cout << res;

	return 0;
}