//
// Created by onglu on 2022/5/26.
//

#include <bits/stdc++.h>
#define double long double
#define cpab const Point &a, const Point &b
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
#define int long long
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
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}
Point operator+(cpab) { return {a.x + b.x, a.y + b.y}; }
Point operator-(cpab) { return {a.x - b.x, a.y - b.y}; }
Point operator+(const Point &a, const double &b) { return {a.x + b, a.y}; }
Point operator-(const Point &a, const double &b) { return {a.x - b, a.y}; }
Point operator*(const Point &a, const double &b) { return {a.x * b, a.y * b}; }
Point operator*(const double &b, const Point &a) { return {a.x * b, a.y * b}; }
Point operator/(const Point &a, const double &b) { return {a.x / b, a.y / b}; }
Point operator*(cpab) { return {a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x}; }
Point operator/(cpab) { return a * Point(b.x, -b.y) / (b.x * b.x + b.y * b.y); }

double dot(cpab) {
    return a.x * b.x + a.y * b.y;
}
double det(cpab) {
    return a.x * b.y - a.y * b.x;
}

Point rot(const Point &a, double angle) {
    return {a.x * cos(angle) - a.y * sin(angle), a.x * sin(angle) + a.y * cos(angle)};
}

int n = 5, k = 7, a[N];
Point Pow(Point a, int p) {
    Point ans(1, 0);
    for( ; p; p >>= 1, a = a * a)
        if(p & 1)
            ans = ans * a;
    return ans;
}
void work() {
    cin >> n >> k;
    int d = k / 2;
    int s = (1 + sqrt(1 + 8 * n / d)) / 2;
    if(s * (s + 1) / 2 * d > n) s -= 1;
    if(s * (s + 1) / 2 * d < n && (s + 2) * (s + 1) / 2 * d <= n) s -= 1;
    int t = (n - s * (s + 1) / 2 * d) / (s + 1);
    int x = (n - s * (s + 1) / 2 * d) % (s + 1);
    int startp = s * d + t;
    Point w(cos(2 * Pi / k), sin(2 * Pi / k));
    if(startp < )
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    int Case = 1;
    cin >> Case;
    while(Case--) work();
    return 0;
}