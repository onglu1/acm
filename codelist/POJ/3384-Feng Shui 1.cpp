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
#include <iomanip>
#include <assert.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
#define double long double
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
const double eps = 1e-18;
int sgn(double x) {
    if(-eps < x && x < eps) return 0;
    else return x > 0 ? 1 : -1;
}
struct Point {
    double x, y;
    int quad() const { return sgn(y) == 1 || (sgn(y) == 0 && sgn(x) >= 0); }
    Point(const double &a, const double &b) : x(a), y(b) {}
};
Point operator+(const Point &a, const Point &b) { return {a.x + b.x, a.y + b.y}; }
Point operator-(const Point &a, const Point &b) { return {a.x - b.x, a.y - b.y}; }
Point operator*(const Point &a, const double &b) { return {a.x * b, a.y * b}; }
Point operator*(const double &b, const Point &a) { return {a.x * b, a.y * b}; }
Point operator/(const Point &a, const double &b) { return {a.x / b, a.y / b}; }
double dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
double det(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}
struct Line {
    Point s, t;
    int include(const Point &p) const {
        return sgn(det(t - s, p - s)) > 0;
    }
    Line(const Point &a, const Point &b) : s(a), t(b) {}
};
Point l_intersection(const Line &a, const Line &b) {
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
vector<Point> half_intersectipon (vector<Line> &l) {
    sort(l.begin(), l.end());
    deque<Line> q;
    for(int i = 0; i < l.size(); i++) {
        if(i && sameDir(l[i], l[i - 1])) continue;
        while(q.size() > 1 && !check(q[q.size() - 2], q[q.size() - 1], l[i])) q.pop_back();
        while(q.size() > 1 && !check(q[0], q[1], l[i])) q.pop_front();
        q.push_back(l[i]);
    }
    while(q.size() > 2 && !check(q[q.size() - 2], q[q.size() - 1], q[0])) q.pop_back();
    while(q.size() > 2 && !check(q[0], q[1], q[q.size() - 1])) q.pop_front();
    vector<Point> ret;
    for(int i = 0; i < q.size(); i++) ret.push_back(l_intersection(q[i], q[(i + 1) % q.size()]));
    return ret;
}
double abs(const Point &p) {
    return sqrt(dot(p, p));
}
Point normL(const Line &l) {
    Point t = l.t - l.s;
    return Point(-t.y, t.x) / abs(t);
}

int n, r;
void work() {
    vector<Point> p;
    for(int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
//        scanf("%Lf%Lf", &x, &y);
        p.push_back({x, y});
    }
    std::reverse(p.begin(), p.end());
    vector<Line> edg;
    for(int i = 0; i < n; i++) {
        Line l = Line(p[i], p[(i + 1) % p.size()]);
        Point norm = normL(l);
        edg.push_back(Line(l.s + norm * r, l.t + norm * r));
    }
    vector<Point> inside = half_intersectipon(edg);
//    assert(inside.size() != 0);
    if(inside.size() <= 1) {
        cout << fixed << setprecision(6) << inside[0].x << " " << inside[0].y << " " << inside[0].x << " " << inside[0].y << endl;
//        printf("%.6Lf %.6Lf %.6Lf %.6Lf\n", inside[0].x, inside[0].y, inside[0].x, inside[0].y);
    } else {
        int x = 0, y = 1;
        for(int i = 0; i < inside.size(); i++) {
            for(int j = i + 1; j < inside.size(); j++) {
                if(sgn(abs(inside[i] - inside[j]) - abs(inside[x] - inside[y])) > 0) {
                    x = i;
                    y = j;
                }
            }
        }
        cout << fixed << setprecision(6) << inside[x].x << " " << inside[x].y << " " << inside[y].x << " " << inside[y].y << " " << endl;
//        printf("%.6Lf %.6Lf %.6Lf %.6Lf\n", inside[x].x, inside[x].y, inside[y].x, inside[y].y);
    }

}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout << fixed << setprecision(6);
    while(~scanf("%d %d", &n, &r)) work();
    return 0;
}