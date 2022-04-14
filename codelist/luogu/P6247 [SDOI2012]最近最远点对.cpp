//
// Created by onglu on 2022/4/13.
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
const double Pi = acos(-1.0);
const double eps = 1e-11;
int sgn(double x) {
    if(-eps < x && x < eps) return 0;
    else return x < 0 ? -1 : 1;
}
struct Point {
    double x, y;
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}
};
struct Line{
    Point s, t;
    Line() {}
    Line(const Point &s, const Point &t) : s(s), t(t) {}
};

Point operator+(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator-(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator*(const Point &a, const double &c) { return Point(c * a.x, c * a.y); }
Point operator/(const Point &a, const double &c) { return Point(a.x / c, a.y / c); }
inline bool operator < (const Point &a, const Point &b) {
    return sgn(a.x - b.x) < 0 || (sgn(a.x - b.x) == 0 && sgn(a.y - b.y) < 0);
}
bool operator == (const Point& a, const Point& b) { return !sgn(a.x - b.x) && !sgn(a.y - b.y); }
double dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
double det(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
double abs(const Point &a){ return sqrt(a.x * a.x + a.y * a.y); }
Point rot(const Point &a, double theta){ return Point(a.x * cos(theta) - a.y * sin(theta), a.x * sin(theta) + a.y * cos(theta)); }
Point rotCCW90(const Point &a) { return Point(-a.y, a.x); }
Point rotCW90(const Point &a) { return Point(a.y, -a.x); }
int n;
vector<Point> v;
int cmp(const Point &a, const Point &b) {
    return sgn(a.x - b.x) < 0 || (sgn(a.x - b.x) == 0 && sgn(a.y - b.y) < 0);
}
double rotatingCalipers(const vector<Point> &s) {
    if(s.size() == 2) return abs(s[1] - s[0]);
    int i = 0, j = 0;
    for(int k = 0; k < s.size(); k++) {
        if( cmp(s[i], s[k])) i = k;
        if(!cmp(s[j], s[k])) j = k;
    }
    double ans = 0;
    int si = i, sj = j;
    do{
        ans = max(ans, abs(s[i] - s[j]));
        if(sgn(det(s[(i + 1) % s.size()] - s[i], s[(j + 1) % s.size()] - s[j])) < 0)
            i = (i + 1) % s.size();
        else j = (j + 1) % s.size();
    } while(i != si || j != sj);
    return ans;
}
vector<Point> Convex_hull(vector<Point> &s) {
    sort(s.begin(), s.end());
    vector<Point> ret(s.size() * 2);
    int sz = 0;
    for(int i = 0; i < s.size(); i++) {
        while(sz > 1 && sgn(det(ret[sz - 1] - ret[sz - 2], s[i] - ret[sz - 2])) < 0) sz--;
        ret[sz++] = s[i];
    }
    int k = sz;
    for(int i = s.size() - 2; i >= 0; i--) {
        while(sz > 1 && sgn(det(ret[sz - 1] - ret[sz - 2], s[i] - ret[sz - 2])) < 0) sz--;
        ret[sz++] = s[i];
    }
    ret.resize(sz - (s.size() > 1));
    return ret;
}
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        double x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    srand(12093);
    double ans1 = abs(v[0] - v[1]);
    for(int i = 0; i < 5; i++) {
        double ang = ((double)rand() / RAND_MAX) * Pi;
        for(int j = 0; j < n; j++) {
            v[j] = rot(v[j], ang);
        }
        std::sort(v.begin(), v.end());
        for(int j = 0; j < n; j++) {
            for(int k = j; k < min(n, j + 5); k++) if(k != j) {
                    ans1 = min(ans1, abs(v[j] - v[k]));
                }
        }
    }
    v = Convex_hull(v);
    double ans2 = rotatingCalipers(v);
    cout << fixed << setprecision(8) << ans1 << " " << ans2 << endl;
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