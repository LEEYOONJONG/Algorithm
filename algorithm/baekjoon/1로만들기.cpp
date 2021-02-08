#include <iostream>
using namespace std;
int cache[1000000];
int making(int n) { //return하는 것은 1이 되기위해 추가로 필요한 횟수
	if (n == 1) return 0;
	if (cache[n] != 0) return cache[n];
	int r1 = 1000000, r2 = 1000000, r3 = 1000000;
	if (n % 3 == 0) r1 = 1+making(n/3);
	if (n % 2 == 0) r2 = 1+making(n / 2); // 1
	r3 = 1+making(n - 1); 
	
	int minResult = min(min(r1, r2), r3);
	cache[n] = minResult;
	return minResult;
}


int main() {
	int n;
	cin >> n;
	cout << making(n);
}