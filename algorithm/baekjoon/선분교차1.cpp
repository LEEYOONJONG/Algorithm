#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

long long ccw(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
    long long operation = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
    if (operation > 0) return 1;
    else if (operation == 0) return 0;
    else return -1;
}

long long isIntersect(pair<pair<long long, long long>, pair<long long, long long>> line1, pair<pair<long long, long long>, pair<long long, long long>> line2) {
    pair<long long, long long> a = line1.first;
    pair<long long, long long> b = line1.second;
    pair<long long, long long> c = line2.first;
    pair<long long, long long> d = line2.second;

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
    pair<pair<long long, long long>, pair<long long, long long>> line1;
    pair<pair<long long, long long>, pair<long long, long long>> line2;
    cin >> line1.first.first >> line1.first.second >> line1.second.first >> line1.second.second;
    cin >> line2.first.first >> line2.first.second >> line2.second.first >> line2.second.second;

    cout << isIntersect(line1, line2);
}