#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int main() {
	int c;
	cin >> c;

	for (int i = 0; i < c; i++) {
		string sentence;
		stack<char> s;
		bool isYes=true;
		cin >> sentence;
		for (int j = 0; j < sentence.size(); j++) {
			// 여는 문자가 들어올 때
			if (sentence[j] == '(' || sentence[j] == '{' || sentence[j] == '[') {
				s.push(sentence[j]);
			}
			else { // 닫는 문자가 들어올 때
				if (s.size() == 0) {// 여는 문자가 스택에 없는데 닫는 문자가 들어올 때.
					isYes = false;
					break;
				}
				if (s.top() == '(' && sentence[j] == ')') s.pop();
				else if (s.top() == '{' && sentence[j] == '}') s.pop();
				else if (s.top() == '[' && sentence[j] == ']') s.pop();
				else {
					isYes = false;
					break;
				}
			}
			
		}
		if (isYes == false) {
			cout << "NO" << endl;
			continue;
		}
		else {
			if (s.size() == 0) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}