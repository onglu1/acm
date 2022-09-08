//
// Created by onglu on 2022/5/26.
//

#include <bits/stdc++.h>

#define cpab const Point &a, const Point &b
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
const double eps = 1e-9;
const double Pi = acos(-1.0);
struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
};
istream &operator>>(istream& in, Point &p) {
    in >> p.x >> p.y;
    return in;
}
ostream &operator<<(ostream& out, Point &p) {
    // out << "(" << p.x << ", " << p.y << ")";
    out << "(" << p.x << ", " << p.y << ", " << p.x + p.y << ")";
    return out;
}
Point operator+(cpab) { return {a.x + b.x, a.y + b.y}; }
Point operator-(cpab) { return {a.x - b.x, a.y - b.y}; }
Point operator*(const Point &a, const double &b) { return {a.x * b, a.y * b}; }
Point operator/(const Point &a, const double &b) { return {a.x / b, a.y / b}; }

double dot(cpab) {
    return a.x * b.x + a.y * b.y;
}
double det(cpab) {
    return a.x * b.y - a.y * b.x;
}

Point rot(const Point &a, double angle) {
    return {a.x * cos(angle) - a.y * sin(angle), a.x * sin(angle) + a.y * cos(angle)};
}
int n = 5, k = 10, a[N];

void work() {
    cout << fixed << setprecision(3);
    int k2 = k / 2;
    int cycle = (k & 1) ? k * k2 : k;
    Point now(0, 0);
    int cnt = 0;
    Point dir(1, 0);
    do {
        cout << now << " ";
        cnt += 1;
        if(cnt % cycle == 0) cout << endl;
        now = now + dir * ((cnt - 1) / k2 + 1);
        dir = rot(dir, 2 * Pi / k);
    } while(cnt <= k * k2 * 7);
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
//    cin >> Case;
    while(Case--) work();
    return 0;
}