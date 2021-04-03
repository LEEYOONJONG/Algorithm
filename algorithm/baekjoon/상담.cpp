#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;

int arrT[6], arrP[6];
int n;

int outing(int start) {
	if (start >= n) return 0;

	int sum = arrP[start];
	for (int i = start + arrT[start]; i < n; i++) {
		sum += outing(i);
	}

}

int main()
{
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arrT[i] >> arrP[i];
	}

	int max = -1;
	for (int i = 0; i < n; i++) {
		int tmp = outing(i);
		if (tmp > max) max = tmp;
	}
	