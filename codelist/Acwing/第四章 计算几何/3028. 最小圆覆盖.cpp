//
// Created by onglu on 2022/4/11.
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
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
const double eps = 1e-8;
int sgn(double x) {
    if(-eps < x && x < eps) return 0;
    else return x > 0 ? 1 : -1;
}
struct Point {
    double x, y;
    Point(const double &a, const double &b) : x(a), y(b) {}
};
Point operator+(const Point &a, const Point &b) { return {a.x + b.x, a.y + b.y}; }
Point operator-(const Point &a, const Point &b) { return {a.x - b.x, a.y - b.y}; }
Point operator*(const Point &a, const double &b) { return {a.x * b, a.y * b}; }
Point operator/(const Point &a, const double &b) { return {a.x / b, a.y / b}; }
double det(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}
double dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
struct Line {
    Point s, t;
    Line(const Point &a, const Point &b) : s(a), t(b) {}
};
Point l_intersection(const Line &a, const Line &b) {
    double s1 = det(a.t - a.s, b.s - a.s), s2 = det(a.t - a.s, b.t - a.s);
    return (b.s * s2 - b.t * s1) / (s2 - s1);
}
Line norm(const Line &a) {
    Point mid = (a.t + a.s) / 2;
    Point dir = a.t - a.s;
    dir = {dir.y, -dir.x};
    return Line(mid, mid + dir);
}
double abs(const Point &a, const Point &b) {
    return sqrt(dot(a - b, a - b));
}
struct Circle {
    Point o;
    double r;
    Circle(const Point &o, const double &r) : o(o), r(r) {}
    Circle(const Point &a, const Point &b, const Point &c) : o(0, 0) {
        Line ab = norm(Line(b, a));
        Line bc = norm(Line(b, c));
        o = l_intersection(ab, bc);
        r = abs(o, a);
    }
};


int n, m, a[N];
vector<Point> v;
void work() {
    cin >> n;
    srand(12391278);
    for(int i = 1; i <= n; i++) {
        double x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    random_shuffle(v.begin(), v.end());
    Circle ans = {v[0], 0};
    for(int i = 1; i < n; i++) {
        if(abs(ans.o, v[i]) > ans.r + eps) {
            ans = {v[i], 0};
            for(int j = 0; j < i; j++) {
                if(abs(ans.o, v[j]) > ans.r + eps) {
                    ans = {(v[i] + v[j]) / 2, abs(v[i], v[j]) / 2};
                    for(int k = 0; k < j; k++) {
                        if(abs(ans.o, v[k]) > ans.r + eps) {
                            ans = Circle(v[i], v[j], v[k]);
                        }
                    }
                }
            }
        }
    }
    cout << fixed << setprecision(10) << ans.o.x << " " << ans.o.y << " " << ans.r << endl;
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
    while (Case--) work();
    return 0;
}