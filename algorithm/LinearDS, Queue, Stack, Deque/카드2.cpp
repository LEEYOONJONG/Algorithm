#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main() {
	int n;
	cin >> n;

	deque<int> d;

	for (int i = 1; i <= n; i++) {
		d.push_back(i);
	}
	while (d.size() != 1) {
		d.pop_front(); // 맨 위 버리고
		int tmp = d.front();
		d.pop_front();
		d.push_back(tmp);
	}
	cout << d.front();

	return 0;
}