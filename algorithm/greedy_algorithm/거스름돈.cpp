#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	n = 1000 - n;
	//720
	int count = 0;
	count += n / 500;
	n -= 500 * (n / 500);
	//220
	count += n / 100;
	n -= 100 * (n / 100);
	//20
	count += n / 50;
	n -= 50 * (n / 50);

	count += n / 10;
	n -= 10 * (n / 10);


	count += n / 5;
	n -= 5 * (n / 5);

	count += n / 1;
	n -= 1 * (n / 1);
	cout << count;
}