#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-8;
const int N = 2e5 + 1009;
int sgn(long double x) {
    if(-eps < x && x < eps) return 0;
    else return x > 0 ? 1 : -1;
}
struct Point {
    long double x, y;
    int quad() const {return (sgn(y) == 1) || (sgn(y) == 0 && sgn(x) >= 0);}
    Point(long double a, long double b) : x(a), y(b) {}
};
Point operator+(const Point &a, const Point &b) { return {a.x + b.x, a.y + b.y}; }
Point operator-(const Point &a, const Point &b) { return {a.x - b.x, a.y - b.y}; }
Point operator*(const Point &a, long double b) { return {a.x * b, a.y * b}; }
Point operator*(long double b, const Point &a) { return {a.x * b, a.y * b}; }
Point operator/(const Point &a, long double b) { return {a.x / b, a.y / b}; }
Point operator/(long double b, const Point &a) { return {a.x / b, a.y / b}; }
long double dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
long double det(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}
struct Line {
    Point s, t;
    bool include(const Point &p) const {
        return sgn(det(t - s, p - s)) > 0;
    }
};
Point l_intersection(const Line &a, const Line &b) {
    long double s1 = det(a.t - a.s, b.s - a.s), s2 = det(a.t - a.s, b.t - a.s);
    return (b.s * s2 - b.t * s1) / (s2 - s1);
}
bool operator<(const Point &a, const Point &b) {
    if(a.quad() != b.quad()) return a.quad() < b.quad();
    else return sgn(det(a, b)) > 0;
}
bool parllel(const Line &a, const Line &b) {
    return !sgn(det(a.t - a.s, b.t - b.s));
}
bool sameDir(const Line &a, const Line &b) {
    return parllel(a, b) && (sgn(dot(a.t - a.s, b.t - b.s)) > 0);
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
vector<Point> half_intersection(vector<Line> &l) {
    sort(l.begin(), l.end());
    deque<Line> q;
    for(int i = 0; i < l.size(); i++) {
        if(i && sameDir(l[i], l[i - 1])) {
            continue;
        }
        while (q.size() > 1 && !check(q[q.size() - 2], q[q.size() - 1], l[i])) q.pop_back();
        while (q.size() > 1 && !check(q[0], q[1], l[i])) q.pop_front();
        q.push_back(l[i]);
    }
    while (q.size() > 2 && !check(q[q.size() - 2], q[q.size() - 1], q[0])) q.pop_back();
    while (q.size() > 2 && !check(q[0], q[1], q[q.size() - 1])) q.pop_front();
    vector<Point> ret;
    for (int i = 0; i < q.size(); i++) {
//        printf("%.2Lf %.2Lf %.2Lf %.2Lf\n", q[i].s.x, q[i].s.y, q[i].t.x, q[i].t.y);
        ret.push_back(l_intersection(q[i], q[(i + 1) % q.size()]));
    }
//    printf("\n");
    return ret;
}
int n;
double v[N], k[N];
vector<Line> t, ori;
signed main()
{
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\Desktop\\3190\\5.in", "r", stdin);
//    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
//    printf("%.2Lf %.2Lf\n", 899420952 + 3359708* (long double)0.17, 899968009 +
//            84530 * (long double)0.17);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for(int i = 1; i <= n; i++) {
        double kk = k[i];
        double vv = v[i];
        t.push_back({Point(0, kk), Point(1, kk + vv)});
        ori.push_back({Point(0, kk), Point(1, kk + vv)});
    }
    const long double INF = 1e50;
    t.push_back({Point(0, INF), Point(0, 0)});
    t.push_back({Point(1, INF), Point(0, INF)});
    vector<Point> p = half_intersection(t);

    vector<int> ans;
    for(auto x : p) {
//        printf("%.2Lf %.2Lf\n", x.x, x.y);
//        cout << x.x << " " << x.y << endl;
        for(int i = 0; i < ori.size(); i++) {
            auto l = ori[i];
            if(sgn(det(l.t - x, l.t - l.s)) == 0) {
                ans.push_back(i + 1);
            }
        }
    }
    std::sort(ans.begin(), ans.end());
    ans.resize(std::unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
    return 0;
}