//
// Created by onglu on 2022/3/18.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define nxt(i) ((i + 1) % s.size())

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
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

int n;
typedef vector<Point> Polygon;
Polygon Convex_hull(Polygon &s) {
    sort(s.begin(), s.end());
    int un = 0;
    for(int i = 0; i < s.size(); i++) {
        if(i == 0 || sgn(dot(s[i] - s[i - 1], s[i] - s[i - 1])) != 0) {
            s[un++] = s[i];
        }
    }
    s.resize(un);
    Polygon ret(s.size() * 2);
    int sz = 0;
    for(int i = 0; i < s.size(); i++) {
        while(sz > 1 && sgn(cross(ret[sz - 1], s[i], ret[sz - 2])) < 0) sz--;
        ret[sz++] = s[i];
    }
    int k = sz;
    for(int i = s.size() - 2; i >= 0; i--) {
        while(sz > 1 && sgn(cross(ret[sz - 1], s[i], ret[sz - 2])) < 0) sz--;
        ret[sz++] = s[i];
    }
    ret.resize(sz - (s.size() > 1));
    return ret;
}
double a, b, r;
void work() {
    scanf("%d", &n);
    Polygon p;
    scanf("%lf %lf %lf", &a, &b, &r);
    for(int i = 1; i <= n; i++) {
        double x, y, theta;
        scanf("%lf %lf %lf", &x, &y, &theta);
        p.push_back(Point(x, y) + rot(Point(b / 2 - r, 0) + Point(0, a / 2 - r), theta));
        p.push_back(Point(x, y) + rot(Point(b / 2 - r, 0) - Point(0, a / 2 - r), theta));
        p.push_back(Point(x, y) - rot(Point(b / 2 - r, 0) + Point(0, a / 2 - r), theta));
        p.push_back(Point(x, y) - rot(Point(b / 2 - r, 0) - Point(0, a / 2 - r), theta));
    }
    Polygon s = Convex_hull(p);
    double ans = 0;
    for(int i = 0; i < s.size(); i++) {
//        int pre = (i - 1 + (int)s.size()) % s.size();
        double l = abs(s[nxt(i)] - s[i]);
//        double ll = abs(s[pre] - s[i]);
        ans += l;
//        if(fabs(dot(s[nxt(i)] - s[i], s[pre] - s[i]) / l / ll) < 1 - 1e-11) {
//            double theta1 = fabs(acos(dot(s[nxt(i)] - s[i], s[pre] - s[i]) / l / ll));
//            double theta2 = Pi - theta1;
//            ans += r * theta2;
//        }
    }

    printf("%.2f\n", ans + 2 * Pi * r);


}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    work();
    return 0;
}