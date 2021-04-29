#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;

int arrT[16], arrP[16];
int n;

int outing(int start) {
	cout << start << endl;

	if (start+arrT[start] > n) return 0;

	int maximum = arrP[start];
	int sum = arrP[start];

	for (int i = start+1; i < n; i++) {
		if (i + arrT[i] >= n) continue;
		sum += outing(i);
		if (sum > maximum) maximum = sum;
		sum = arrP[start];
	}

	return maximum;

}

int main()
{

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arrT[i] >> arrP[i];
	}
	
	int maxi = -1;
	for (int i = 0; i < n; i++) {
		int tmp = outing(i);
		if (tmp > maxi) maxi = tmp;
	}

	cout << maxi;
}
	