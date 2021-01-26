#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//ù �� ���� ��������
bool SortSecCol1(const vector<int>& v1, const vector<int>& v2) {
	return v1[0] < v2[0];
}
//��° �� ���� ��������
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

		//ù �� ���� �������� ����
		sort(arr.begin(), arr.end(), SortSecCol1);
		
		int min = arr[0][1];
		int count = 1;
		for (int j = 1; j < n; j++) {
			//�ּҰ��� �߰ߵ� ������ ī��Ʈ++
			if (arr[j][1] < min) {
				count++;
				min = arr[j][1];
			}
		}
		cout << count<<endl;

		
	}
}