#include <iostream>
#include <deque>
#include <queue>
#include <string>
#include <vector>
using namespace std;

vector<int> tree[50001];
int parent[50001];
bool check[50001];

void findfirstParent(int n) {              // n�� ���� ���
    check[n] = true;

    for (int i = 0; i < tree[n].size(); i++) {
        int idx = tree[n][i];       
        if (check[idx] == true) continue;
        parent[idx] = n; 
        findfirstParent(idx);
    }
}


void common(int a, int b) { 
    // a�� b�� ���� ���
    if (a == b) {
        cout << a << endl;
        return;
    }
    // �ٸ��ٸ�
    else {
        int aAnc = a;   // ancestor of a
        int bAnc;       // ancestor of b
        int count1 = 0; // a�� �ϴ� ������ b�� ��ü Ž������ �� Ž������ ī��Ʈ
        int mem1 = -1;  // ������ Ž���Ͽ� ���� ã���� �� �� ��尪�� �����ϴ� ����
        bool isfound = false;
        while (!isfound) { // a ���� Ž��
            bAnc = b;
          
            if (aAnc == bAnc) {
                mem1 = bAnc;
                isfound = true;
            }

            while (!isfound && bAnc != 1) { // b���� Ž��
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
        int count2 = 0; // b�� �ϴ� ������ a�� ��ü Ž��
        int mem2 = -1;
        isfound = false;
        while (!isfound) { // b ���� Ž��
            aAnc = a;
            
            if (aAnc == bAnc) {
                mem2 = aAnc;
                isfound = true;

            }


            while (!isfound && aAnc != 1) { // a ���� Ž��
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
        else { //ī��Ʈ�� �ּҰ� �Ǵ� ��带 ����ؾ� ��.
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

