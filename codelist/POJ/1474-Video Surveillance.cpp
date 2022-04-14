
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
const double eps = 1e-10;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int sgn(double x) {
    if(fabs(x) < eps) return 0;
    else return x > 0 ? 1 : -1;
}
struct Point {
    double x, y;
    int quad() const {return sgn(y) == 1 || (sgn(y) == 0 && sgn(x) >= 0);}
    Point(double a, double b) : x(a), y(b) {}
};
Point operator+(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator-(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator*(const Point &a, const double &c) { return Point(c * a.x, c * a.y); }
Point operator/(const Point &a, const double &c) { return Point(a.x / c, a.y / c); }
double dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
double det(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}
struct Line {
    Point s, t;
    bool include(const Point &p) const { return sgn(det(t - s, p - s)) >= 0;}
    Line(Point a, Point b) : s(a), t(b) {}
};

Point l_intersection(const Line& a, const Line& b) {
    double s1 = det(a.t - a.s, b.s - a.s), s2 = det(a.t - a.s, b.t - a.s);
    return (b.s * s2 - b.t * s1) / (s2 - s1);
}
bool operator<(const Point &a, const Point &b) {
    if(a.quad() != b.quad()) {
        return a.quad() < b.quad();
    }
    return sgn(det(a, b)) > 0;
}
bool parallel(const Line &a, const Line &b) {
    return !sgn(det(a.t - a.s, b.t - b.s));
}
bool sameDir(const Line &a, const Line &b) {
    return parallel(a, b) && (sgn(dot(a.t - a.s, b.t - b.s)) == 1);
}
bool operator<(const Line &a, const Line &b) {
    if(sameDir(a, b)) {
        return b.include(a.s);
    } else {
        return (a.t - a.s) < (b.t - b.s);
    }
}
bool check(const Line &u, const Line &v, const Line &w) {
    return w.include(l_intersection(u, v));
}
int half_intersection(vector<Line> &l) {
    sort(l.begin(), l.end());
    deque<Line> q;
    q.clear();
    for(int i = 0; i < l.size(); i++) {
        if(i && sameDir(l[i], l[i - 1])) {
            continue;
        }
        while(q.size() > 1 && !check(q[q.size() - 2], q[q.size() - 1], l[i])) q.pop_back();
        while(q.size() > 1 && !check(q[1], q[0], l[i])) q.pop_front();
        q.push_back(l[i]);
    }
    while(q.size() > 1 && !check(q[q.size() - 2], q[q.size() - 1], q[0])) q.pop_back();
    while(q.size() > 1 && !check(q[1], q[0], q[q.size() - 1])) q.pop_front();
    return q.size() > 2;
}
int n;
vector<Point> p;
int work() {
//    cin >> n;
    p.clear();
    for(int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }
    vector<Line> v;
    v.clear();
    reverse(p.begin(), p.end());
    for(int i = 0; i < p.size(); i++) {
        v.push_back({p[i], p[(i + 1) % p.size()]});
    }
    return half_intersection(v);
}
signed main()
{
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios ::sync_with_stdio(0);
    cin.tie(0);
    int Case;
//    cin >> Case;
    while(cin >> n) {
        if(n == 0) break;
        static int cnt = 0;
        cnt++;
        cout << "Floor #" << cnt << endl;
        cout << (work() ? "Surveillance is possible." : "Surveillance is impossible.") << endl << endl;
    }
    return 0;
}