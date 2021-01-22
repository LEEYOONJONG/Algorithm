#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//n�� 2�� ���Ϳ��� 2���� �������� �������� ������ ���� �Լ�
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
		//2���� �������� �������� ���� ����.
		sort(arr.begin(), arr.end(), SortSecCol);

		int sumWarming = 0;
		int ret = -1;
		for (int j = 0; j < n; j++) {
			//�ʱ� ���� ����
			if (j == 0) {
				ret = arr[j][0] + arr[j][1];
				sumWarming += arr[j][0];
			}

			else {
				// n-1��° ����� �Դ� �ð��� �ش������� ���� �ɸ���,
				// n��° ����� ����� �ð��� �Դ� �ð��� ª�� ������ ���
				ret = max(ret, sumWarming + arr[j][0] + arr[j][1]);
				sumWarming += arr[j][0];
			}
		}
		cout << ret << endl;
	}
}