//
// Created by onglu on 2022/5/18.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
const double eps = 1e-9;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, a[N];
inline int cmp(double a) {
    return a < -eps ? -1 : a > eps;
}
inline double Sqr(double a) {
    return a * a;
}
inline double Sqrt(double a) {
    return a <= 0 ? 0 : sqrt(a);
}

struct Point {
    double x, y,z;
    Point() {}
    Point(double x, double y, double z) :x(x), y(y), z(z) {}
    double len() const {
        return Sqrt(Sqr(x) + Sqr(y) + Sqr(z));
    }
};
Point operator+(const Point &a, const Point &b) {return {a.x + b.x, a.y + b.y, a.z + b.z}; }
Point operator-(const Point &a, const Point &b) {return {a.x - b.x, a.y - b.y, a.z - b.z}; }
Point operator*(const Point &a, const double &b) {return {a.x * b, a.y * b, a.z * b}; }
Point operator/(const Point &a, const double &b) {return {a.x / b, a.y / b, a.z / b}; }
Point unit(const Point &p) {
    return p / p.len();
}
Point det(const Point &a, const Point &b) {
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}
double dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
Point rotate(Point a, Point b, double angle) {
    Point e1, e2, e3;
    e3 = unit(b);
    double len = dot(a, e3);
    Point p = e3 * len;
    e1 = a - p;
    if(unit(e1).len() > (1e-8)) e1 = unit(e1);
    e2 = det(e1, e3);
    double x1 = dot(a, e1), y1 = dot(a, e2);
    double x = x1 * cos(angle) - y1 * sin(angle);
    double y = x1 * sin(angle) + y1 * cos(angle);
    return e1 * x + e2 * y + p;
}
istream &operator>>(istream &in, Point &p) {
    in >> p.x >> p.y >> p.z;
    return in;
}
ostream &operator<<(ostream &out, Point &p) {
    out << p.x << " " << p.y << " " << p.z;
    return out;
}
void work() {
    Point A, B;
    double r;
    cin >> A >> B >> r;
    r = r / 180 * acos(-1.0);
    // cout << r << endl;
    Point X, Y;
    X = rotate(B, A, r);
    Y = rotate(B, A, -r);
    if(X.z > Y.z) cout << X << endl;
    else cout << Y << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
    cout << fixed << setprecision(10);
    cin >> Case;
    while(Case--) work();
    return 0;
}