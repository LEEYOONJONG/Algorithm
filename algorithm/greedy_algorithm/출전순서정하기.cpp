#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
bool comp(int a, int b) {
	if (a > b) return true;
	else return false;
}

int main() {

	int c;
	cin >> c;
	for (int i = 0; i < c; i++) {
		int n;
		cin >> n;
		deque<int> ateam;
		deque<int> bteam;

		for (int j = 0; j < n; j++) {
			int inputA;
			cin >> inputA;
			ateam.push_back(inputA);
		}
		for (int j = 0; j < n; j++) {
			int inputB;
			cin >> inputB;
			bteam.push_back(inputB);
		}
		sort(ateam.begin(), ateam.end(), comp);
		sort(bteam.begin(), bteam.end(), comp);
		int count = 0;
		for (int k = 0; k < n; k++) {
			if (ateam[0] > bteam[0]) {
				ateam.pop_front();
				bteam.pop_back();
			}
			else {
				count++;
				ateam.pop_front();
				bteam.pop_front();
			}
		}
		cout << count << endl;

	}
}