#include <iostream>
#include <deque>
#include <string>
#include <vector>
using namespace std;

vector<int> arr;

void func(int pivot, int end) { // (0, 8)
    if (pivot == -1) return; // small�� ������
    if (pivot > end) return; // big�� ������,
    if (pivot == end) {
        cout << arr[pivot] << '\n';
        return;
    }

    int small = -1, big = end + 1;

    for (int i = pivot + 1; i <= end; i++) {
        if (arr[pivot] > arr[i]) { //�Ǻ����� ������ �߽߰�
            small = i;
            break;
        }
    }
    for (int i = pivot + 1; i <= end; i++) {
        if (arr[pivot] < arr[i]) {
            big = i;
            break;
        }
    }

    func(small, big - 1); //small�� �Ǻ�

    func(big, end); //big�� �Ǻ�

    cout << arr[pivot] << '\n';
}

int main() {

    int x;
    while (cin >> x) {

        // if (x=='\n') continue; 10�� �� Ʋ����
        arr.push_back(x);
    }

    int end = (int)arr.size() - 1;

    func(0, end);
}
