#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
#include <limits.h>
using namespace std;

int main() {
	int n;
	long long zero[100];
	long long one[100];

	cin >> n;

	zero[1] = 0;
	one[1] = 1;

	for (int i = 2; i <= n; i++) {
		zero[i] = zero[i - 1] + one[i - 1];
		one[i] = zero[i - 1];
	}

	cout << zero[n] + one[n];

	return 0;
}