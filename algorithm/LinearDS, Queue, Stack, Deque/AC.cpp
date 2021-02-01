#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main() {
    // string�� char �߰�(+=) ����
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string p;
        cin >> p; // RDD

        int n;
        cin >> n; // 4 (4���� �迭 ����)

        // case 1: ���� D�� ������ n���� ũ�ٸ� error
        int dCount = 0;
        for (int j = 0; j < p.size(); j++) {
            if (p[j] == 'D') dCount++;
        }

        if (dCount > n) {
            // ���Ļ� while������
            char chch;
            cin.get(chch); //enter �ñ�
            while (cin.get(chch))
                if (chch == '\n') break;
            // error ����� ��.
            cout << "error" << endl;
            continue;
        }
        // case 2: D�� ������ �ʰ����� �ʾƵ� �Է��� 0����� [] �Է��� ���Ļ����� �޾ƾ���.
        if (n == 0) {
            char chch;
            cin.get(chch);
            while (cin.get(chch))
                if (chch == '\n') break;
            // �� �迭 ��� �� ��.
            cout << "[]" << endl;
            continue;
        }

        ////
        char input;
        deque<string> d;
        string tempStr = "";
        int nCount = 0;

        // D�� �迭�� ������ �ʰ������� ������ n�� 0�� �ƴ� ��
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

        int reverseCount = 0; //Reverse ��, ���� ������ ���� count

        for (int j = 0; j < p.size(); j++) { //RDD�̹Ƿ� 3�� ��ȯ.
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