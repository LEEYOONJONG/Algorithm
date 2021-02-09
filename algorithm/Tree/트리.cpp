#include <iostream>
#include <deque>
#include <string>
#include <vector>
using namespace std;
int pre[1001], in[1001];
int n;

void post(int preStart, int preEnd, int inStart, int inEnd) { // 기준은 전위 (0,7,0,7)
    //전위 pivot을 중위에서 찾기
    if (preStart > preEnd || inStart > inEnd) return;
    if (inStart == inEnd) {
        cout << in[inStart] << ' ';
        return;
    }

    int inIndex = -1;

    for (int i = inStart; i <= inEnd; i++) {
        if (pre[preStart] == in[i]) {
            inIndex = i;
        }
    }
    post(preStart + 1, (inIndex - inStart) + preStart, inStart, inIndex - 1);
    post((inIndex - inStart) + preStart + 1, preEnd, inIndex + 1, inEnd);
    cout << in[inIndex] << ' ';

}

int main() {

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> pre[j];
        }
        for (int j = 0; j < n; j++) {
            cin >> in[j];
        }

        post(0, n - 1, 0, n - 1);
        cout << '\n';


    }
}
