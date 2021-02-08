#include <iostream>
#include <deque>
using namespace std;

void plusplus(deque<int> a, deque<int> b) {
	int ollim = 0;
	deque<int> result;
	while (!a.empty() || !b.empty()) {
		int aNum, bNum;
		if (!a.empty()) {
			aNum = a.front();
			a.pop_front();
		}
		else aNum = 0;
		if (!b.empty()) {
			bNum = b.front();
			b.pop_front();
		}
		else bNum = 0;

		if (ollim + aNum + bNum < 10) {
			result.push_front(aNum + bNum + ollim);
			ollim = 0;
		}
		else {
			result.push_front((aNum + bNum + ollim) % 10);
			ollim = 1;
		}
	}
	if (ollim == 1) result.push_front(1);
	while (!result.empty()) {
		cout << result.front();
		result.pop_front();
	}
}
void plusminus(deque<int> bigger, deque<int> smaller) {
	deque<int> result;
	
	while (!bigger.empty() || !smaller.empty()) {
		int bigNum, smallNum;
		if (!bigger.empty()) {
			bigNum = bigger.front();
			bigger.pop_front();
			if (bigNum == -1) {
				bigNum = 9;
				int temp = bigger.front();
				bigger.pop_front();
				bigger.push_front(temp - 1);
			}
		}

		if (!smaller.empty()) {
			smallNum = smaller.front();
			smaller.pop_front();
		}
		else smallNum = 0;
		
		if (bigNum >= smallNum) {
			
			result.push_front(bigNum - smallNum);
		}
		else {
			int temp = bigger.front();
			bigger.pop_front();
			bigger.push_front(temp - 1);
			
			result.push_front(10 + bigNum - smallNum);
		}
	}
	
	while (1) {
		if (result.front() == 0) {
			result.pop_front();
		}
		else break;
	}
	while (!result.empty()) {
		cout << result.front();
		result.pop_front();
	}

}
int main() {
		
		deque<int> a;
		deque<int> b;

		char ch;
		bool aIsMinus = 0, bIsMinus = 0;

		while (cin.get(ch)) {
			if (ch == '-') aIsMinus = 1;
			else if (ch == ' ') break;
			else a.push_front(ch - 48);
		}
		while (cin.get(ch)) {
			if (ch == '-') bIsMinus = 1;
			else if (ch == '\0' || ch == '\n') break;
			else b.push_front(ch - 48);
		}

		if (aIsMinus == 0 && bIsMinus == 0) plusplus(a, b);
		else if (aIsMinus == 1 && bIsMinus == 1) { cout << "-"; plusplus(a, b); }
		else {
			bool aIsBigger;

			if (a.size() > b.size()) aIsBigger = true;
			else if (a.size() < b.size()) aIsBigger = false;
			else {
				bool isSame = true;
				for (int i = a.size()-1; i >=0; i--) {
					
					if (a[i] == b[i]) continue;
					else if (a[i] > b[i]) {
						aIsBigger = true;
						isSame = false;
						break;
					}
					else {
						aIsBigger = false;
						isSame = false;
						break;
					}
				}
				if (isSame) {
					cout << 0;
					return 0;
					
				}
			}
			

			if (aIsBigger) {
				if (aIsMinus) { cout << "-"; plusminus(a, b); }
				else { plusminus(a, b); }
			}
			else { //b가 더 크다
				if (aIsMinus) { plusminus(b, a); }
				else { cout << "-"; plusminus(b, a); }
			}
			return 0;

		}
	
}