#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    long long operation = (long long)(b.first - a.first) * (long long)(c.second - a.second) - (long long)(b.second - a.second) * (long long)(c.first - a.first);
    if (operation > 0) return 1;
    else if (operation == 0) return 0;
    else return -1;
}

int isIntersect(pair<pair<int, int>, pair<int, int>> line1, pair<pair<int, int>, pair<int, int>> line2) {
    pair<int, int> a = line1.first;
    pair<int, int> b = line1.second;
    pair<int, int> c = line2.first;
    pair<int, int> d = line2.second;

    long long ab = ccw(a, b, c) * ccw(a, b, d);
    long long cd = ccw(c, d, a) * ccw(c, d, b);

    if (ab == 0 && cd == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;

}

int main() {
    pair<pair<int, int>, pair<int, int>> line1;
    pair<pair<int, int>, pair<int, int>> line2;
    cin >> line1.first.first >> line1.first.second >> line1.second.first >> line1.second.second;
    cin >> line2.first.first >> line2.first.second >> line2.second.first >> line2.second.second;

    cout << isIntersect(line1, line2);
}