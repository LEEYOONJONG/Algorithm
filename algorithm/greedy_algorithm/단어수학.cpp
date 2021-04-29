#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <math.h>
using namespace std;

vector<string> words;
int alpha[26];
int result[26];

int main() {
    int n;
    cin >> n;


    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        words.push_back(tmp);
        for (int j = 0; j < tmp.length(); j++) {
            alpha[tmp[j] - 'A'] += pow(10, tmp.length() - j - 1);
        }
    }

    ///
//    for (int i=0; i<26; i++){
//        cout<<char('A'+i)<<" : "<<alpha[i]<<endl;
//    }
    //


    for (int h = 9; h >= 0; h--) {
        int sumMax = 0;
        int indexMax = -1;
        for (int i = 0; i < 26; i++) { // 알파벳 중 가장 sum 큰 거
            if (sumMax < alpha[i]) {
                sumMax = alpha[i];
                indexMax = i;
            }
        }
        if (sumMax == 0) break;
        alpha[indexMax] = 0;
        result[indexMax] = h;
        //        cout<<"h가 "<<h<<"일 때, indexmax:"<<indexMax<<", result[indexmax]: "<<result[indexMax] <<endl;
    }
    //
    //    for (int i=0; i<26; i++){
    //        cout<<char('A'+i)<<" : "<<result[i]<<endl;
    //    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < words[i].length(); j++) {
            res += result[words[i][j] - 'A'] * pow(10, words[i].length() - j - 1);
        }
    }
    cout << res;
}