#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main() {
    // string에 char 추가(+=) 가능
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string p;
        cin >> p; // RDD

        int n;
        cin >> n; // 4 (4개의 배열 원소)

        // case 1: 만약 D의 개수가 n보다 크다면 error
        int dCount = 0;
        for (int j = 0; j < p.size(); j++) {
            if (p[j] == 'D') dCount++;
        }

        if (dCount > n) {
            // 형식상 while돌리기
            char chch;
            cin.get(chch); //enter 씹기
            while (cin.get(chch))
                if (chch == '\n') break;
            // error 출력후 끝.
            cout << "error" << endl;
            continue;
        }
        // case 2: D의 개수가 초과하지 않아도 입력이 0개라면 [] 입력은 형식상으로 받아야함.
        if (n == 0) {
            char chch;
            cin.get(chch);
            while (cin.get(chch))
                if (chch == '\n') break;
            // 빈 배열 출력 후 끝.
            cout << "[]" << endl;
            continue;
        }

        ////
        char input;
        deque<string> d;
        string tempStr = "";
        int nCount = 0;

        // D가 배열의 개수를 초과하지도 않으며 n이 0이 아닐 때
        while (cin.get(input) && nCount != n) {
            if (input == '\n') {}
            else if ('0' <= input && input <= '9') {
                tempStr += input;
            }
            else if (input == ',' || input == ']') {

                d.push_back(tempStr);
                tempStr = "";
                nCount++;
            }
            else {}

        }

        int reverseCount = 0; //Reverse 시, 순서 뒤집기 위한 count

        for (int j = 0; j < p.size(); j++) { //RDD이므로 3번 순환.
            if (p[j] == 'R') {
                
                reverseCount++;
            }
            else if (p[j] == 'D') {
                if (reverseCount % 2 == 0) d.pop_front();
                else d.pop_back();
            }
            ///

        }

        cout << "[";
        if (reverseCount % 2 == 0) {
            for (int j = 0; j < d.size(); j++) {
                if (j == d.size() - 1) cout << d[j];
                else cout << d[j] << ",";
            }
        }
        else {
            for (int j = d.size()-1; j >=0 ; j--) {
                if (j == 0) cout << d[j];
                else cout << d[j] << ",";
            }
        }
        cout << "]" << endl;

    }


}