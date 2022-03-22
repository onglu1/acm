//
// Created by onglu on 2022/3/18.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
using namespace std;
const int N = 2e6 + 1009;
const double Pi = acos(-1.0);
const double eps = 1e-11;
int sgn(double x) {
    if(fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}
struct line;
struct Point;
struct Point {
    double x, y;
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}
    Point(const line &l);
};
struct line{
    Point s, t;
    line() {}
    line(const Point &s, const Point &t) : s(s), t(t) {}
};
typedef Point Vector;
Point operator+(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator-(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator*(const Point &a, const double &c) { return Point(c * a.x, c * a.y); }
Point operator/(const Point &a, const double &c) { return Point(a.x / c, a.y / c); }
inline bool operator < (const Point &a, const Point &b) {
    return sgn(a.x - b.x) < 0 || (sgn(a.x - b.x) == 0 && sgn(a.y - b.y) < 0);
}
Point :: Point(const line &l) { *this = l.t - l.s; }
bool operator == (const Point& a, const Point& b) { return !sgn(a.x - b.x) && !sgn(a.y - b.y); }
double dot(const Vector& a, const Vector& b) { return a.x * b.x + a.y * b.y; }
double det(const Vector& a, const Vector& b) { return a.x * b.y - a.y * b.x; }
double cross(const Point& s, const Point& t, const Point& o = Point()) { return det(s - o, t - o); }
double abs(const Point &a){ return sqrt(a.x * a.x + a.y * a.y); }
Point rot(const Point &a, double theta){ return Point(a.x * cos(theta) - a.y * sin(theta), a.x * sin(theta) + a.y * cos(theta)); }
Point rotCCW90(const Point &a) { return Point(-a.y, a.x); }
Point rotCW90(const Point &a) { return Point(a.y, -a.x); }
int s_l_cross(const line &seg, const line &line) {
    int d1 = sgn(cross(line.s, line.t, seg.s));
    int d2 = sgn(cross(line.s, line.t, seg.t));
    if ((d1 ^ d2) == -2) return 1; // proper
    if (d1 == 0 || d2 == 0) return 2;
    return 0;
}
int n;
line l[N];
int check(line cw) {
    if(sgn(dot(cw.s - cw.t, cw.s - cw.t)) == 0) return 0;
    int ok = 1;
    for(int j = 1; j <= n; j++) {
        if(!s_l_cross(l[j], cw)) {
            return 0;
        }
    }
    return 1;
}
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        double x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        l[i] = line({x, y}, {xx, yy});
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(check(line(l[i].s, l[j].t)) || check(line(l[i].s, l[j].s)) ||
                    check(line(l[i].t, l[j].t)) || check(line(l[i].t, l[j].s))) {
                cout << "Yes!" << endl;
                return ;
            }
        }

    }
    cout << "No!" << endl;

}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 0;
    cin >> Case;
    while (Case--) work();
    return 0;
}