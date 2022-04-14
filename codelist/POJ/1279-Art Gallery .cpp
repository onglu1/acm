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
using namespace std;
typedef double D;
const D eps = 1e-9;
const int N = 2e5 + 1009;
int sgn(const D &a) {
    if(-eps < a && a < eps) return 0;
    else return a > 0 ? 1 : -1;
}
struct Point {
    D x, y;
    int quad() const {
        return sgn(y) == 1 || (sgn(y) == 0 && sgn(x) >= 0);
    }
    Point(const D &x, const D &y) : x(x), y(y) {}
};
Point operator+(const Point &a, const Point &b) { return {a.x + b.x, a.y + b.y}; }
Point operator-(const Point &a, const Point &b) { return {a.x - b.x, a.y - b.y}; }
Point operator*(const Point &a, const D &b) { return {a.x * b, a.y * b}; }
Point operator*(const D &b, const Point &a) { return {a.x * b, a.y * b}; }
Point operator/(const Point &a, const D &b) { return {a.x / b, a.y / b}; }
Point operator/(const D &b, const Point &a) { return {a.x / b, a.y / b}; }
D dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
D det(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

struct Line {
    Point s, t;
    bool include(const Point &p) const {
        return sgn(det(t - s, p - s)) > 0;
    }
    Line(const Point &s, const Point &t) : s(s), t(t) {}
};
Point l_intersection(const Line &a, const Line &b) {
    D s1 = det(a.t - a.s, b.s - a.s), s2 = det(a.t - a.s, b.t - a.s);
    return (b.s * s2 - b.t * s1) / (s2 - s1);
}
bool operator<(const Point &a, const Point &b) {
    if(a.quad() != b.quad()) return a.quad() < b.quad();
    return sgn(det(a, b)) > 0;
}
bool parallel(const Line &a, const Line &b) {
    return !sgn(det(a.t - a.s, b.t - b.s));
}
bool sameDir(const Line &a, const Line &b) {
    return parallel(a, b) && (sgn(dot(a.t - a.s, b.t - b.s)) > 0);
}
bool operator<(const Line &a, const Line &b) {
    if(sameDir(a, b)) return b.include(a.s);
    else return (a.t - a.s) < (b.t - b.s);
}
bool check(const Line &u, const Line &v, const Line &w) {
    return w.include(l_intersection(u, v));
}
vector<Point> half_intersection(vector<Line> & l) {
    sort(l.begin(), l.end());
    deque<Line> q;
    for(int i = 0; i < l.size(); i++) {
        if(i && sameDir(l[i], l[i - 1])) {
            continue;
        }
        while(q.size() > 1 && !check(q[q.size() - 2], q[q.size() - 1], l[i])) q.pop_back();
        while(q.size() > 1 && !check(q[0], q[1], l[i])) q.pop_back();
        q.push_back(l[i]);
    }
    while(q.size() > 2 && !check(q[q.size() - 2], q[q.size() - 1], q[0])) q.pop_back();
    while(q.size() > 2 && !check(q[0], q[1], q[q.size() - 1])) q.pop_back();
    vector<Point> ret;
    for(int i = 0; i < q.size(); i++) ret.push_back(l_intersection(q[i], q[(i + 1) % q.size()]));
    return ret;
}
int n;
vector<Point> p;
void work() {
    scanf("%d\n", &n);
    p.clear();
    for(int i = 0; i < n; i++) {
        D x, y;
        scanf("%lf%lf", &x, &y);
        p.push_back({x, y});
    }
//    const D INF = 1e8;
    vector<Line> v;
    std::reverse(p.begin(), p.end());
    for(int i = 0; i < p.size(); i++) {
        v.push_back({p[i], p[(i + 1) % p.size()]});
    }
//    v.push_back({Point(-INF, -INF), Point(-INF + 1, -INF)});
//    v.push_back({Point(-INF, INF), Point(-INF, INF - 1)});
//    v.push_back({Point(INF, INF), Point(INF - 1, INF)});
//    v.push_back({Point(INF, -INF), Point(INF, -INF + 1)});
    vector<Point> ans = half_intersection(v);

    D area = 0;
    for(int i = 0; i < ans.size(); i++) {
        area += det(ans[i], ans[(i + 1) % ans.size()]);
    }
    printf("%.2f\n", fabs(area) / 2);
}
signed main()
{
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    int Case;
    scanf("%d", &Case);
    while(Case--) {
        work();
    }
    return 0;
}