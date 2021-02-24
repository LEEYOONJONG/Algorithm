#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int r, c;
char arr[21][21];


int dfs(int row, int col, bool check[]) {
    int alphabet = int(arr[row][col]);

    if (row < 0 || row >= r || col < 0 || col >= c) return 0;
    if (check[alphabet]) return 0;

    //cout<<arr[row][col]<<" "<<row<<", "<<col<<" =>  check\n";
    check[alphabet] = true;

    bool check1[100], check2[100], check3[100], check4[100];
    //check가 4가지 케이스에 각각 영향없게 해야 함. 이 방법 밖에 모르겠다...
    copy(check, check + 100, check1);
    copy(check, check + 100, check2);
    copy(check, check + 100, check3);
    copy(check, check + 100, check4);


    int up = 1 + dfs(row - 1, col, check1);
    int down = 1 + dfs(row + 1, col, check2);
    int left = 1 + dfs(row, col - 1, check3);
    int right = 1 + dfs(row, col + 1, check4);


    return max(max(up, down), max(left, right));

}

void dfsAll() {
    bool check[100];
    memset(check, false, sizeof(check));
    cout << dfs(0, 0, check);
}

int main() {
    //cout<<int('A'); //65
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    dfsAll();
}