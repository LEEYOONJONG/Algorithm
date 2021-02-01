#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;

int main()
{
	int c;
	int n, k;
	queue<int> q;

	cin >> n >> k;
	//병사 추가하기
	for (int j = 1; j <= n; j++) { // 병사 1부터 병사 n까지 삽입
		q.push(j);
	}
	int tmp = 1;
	bool isFirst = true;
	while (1) {
		if (tmp % k == 0) {
				q.pop();
		}
		else {
			int top = q.front();
			q.pop();
			q.push(top);
		}
		tmp++;
		if (q.size() == 1) {
			cout << q.front();
			break;
		}
	}
	

}