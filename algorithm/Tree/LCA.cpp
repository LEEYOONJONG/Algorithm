#include <iostream>
#include <deque>
#include <queue>
#include <string>
#include <vector>
using namespace std;

vector<int> tree[50001];
int parent[50001];
bool check[50001];

void findfirstParent(int n) {              // n은 시작 노드
    check[n] = true;

    for (int i = 0; i < tree[n].size(); i++) {
        int idx = tree[n][i];       
        if (check[idx] == true) continue;
        parent[idx] = n; 
        findfirstParent(idx);
    }
}


void common(int a, int b) { 
    // a와 b가 같을 경우
    if (a == b) {
        cout << a << endl;
        return;
    }
    // 다르다면
    else {
        int aAnc = a;   // ancestor of a
        int bAnc;       // ancestor of b
        int count1 = 0; // a를 일단 고정후 b를 전체 탐색했을 때 탐색개수 카운트
        int mem1 = -1;  // 조상을 탐색하여 답을 찾았을 때 그 노드값을 저장하는 변수
        bool isfound = false;
        while (!isfound) { // a 조상 탐색
            bAnc = b;
          
            if (aAnc == bAnc) {
                mem1 = bAnc;
                isfound = true;
            }

            while (!isfound && bAnc != 1) { // b조상 탐색
                bAnc = parent[bAnc];
                count1++;
                if (aAnc == bAnc) {
                    mem1 = bAnc;
                    isfound = true;
                }
            }
            if (aAnc == 1) break;
            aAnc = parent[aAnc];
            count1++;

        }



        bAnc = b;
        int count2 = 0; // b를 일단 고정후 a를 전체 탐색
        int mem2 = -1;
        isfound = false;
        while (!isfound) { // b 조상 탐색
            aAnc = a;
            
            if (aAnc == bAnc) {
                mem2 = aAnc;
                isfound = true;

            }


            while (!isfound && aAnc != 1) { // a 조상 탐색
                aAnc = parent[aAnc];
                count2++;
                if (aAnc == bAnc) {
                    mem2 = aAnc;
                    isfound = true;
                }
            }

            if (bAnc == 1) break;
            bAnc = parent[bAnc];
            count2++;

        }

        if (mem1 == -1 || mem2 == -1) { 
            if (mem1 == -1) cout << mem2 << endl;
            else cout << mem1 << endl;
        }
        else { //카운트가 최소가 되는 노드를 출력해야 함.
            if (count1 < count2) cout << mem1 << endl;
            else cout << mem2 << endl;
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    findfirstParent(1);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        common(a, b);
    }

}

