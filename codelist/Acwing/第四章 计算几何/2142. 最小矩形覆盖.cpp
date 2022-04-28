//
// Created by onglu on 2022/4/14.
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
const double eps = 1e-15;

int sgn(double x) {
    if (-eps < x && x < eps) return 0;
    else return x < 0 ? -1 : 1;
}

struct Point {
    double x, y;

    Point() : x(0), y(0) {}

    Point(double x, double y) : x(x), y(y) {}
};


Point operator+(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }

Point operator-(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }

Point operator*(const Point &a, const double &c) { return Point(c * a.x, c * a.y); }

Point operator/(const Point &a, const double &c) { return Point(a.x / c, a.y / c); }

inline bool operator<(const Point &a, const Point &b) {
    return sgn(a.x - b.x) < 0 || (sgn(a.x - b.x) == 0 && sgn(a.y - b.y) < 0);
}

struct Line {
    Point s, t;

    Line() {}

    Line(const Point &s, const Point &t) : s(s), t(t) {}

    Point norm() {
        Point dir = t - s;
        return {-dir.y, dir.x};
    }
};

bool operator==(const Point &a, const Point &b) { return !sgn(a.x - b.x) && !sgn(a.y - b.y); }

double dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }

double det(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }

double abs(const Point &a) { return sqrt(a.x * a.x + a.y * a.y); }

Point rot(const Point &a, double theta) {
    return Point(a.x * cos(theta) - a.y * sin(theta), a.x * sin(theta) + a.y * cos(theta));
}

Point rotCCW90(const Point &a) { return Point(-a.y, a.x); }

Point rotCW90(const Point &a) { return Point(a.y, -a.x); }

double arg(const Point &a) {
    double t = atan2(a.y, a.x);
    return t < 0 ? t + 2 * Pi : t;
}

double cross(const Point& s, const Point& t, const Point& o = Point()) { return det(s - o, t - o); }
vector<Point> Convex_hull(vector<Point> &s) {
    sort(s.begin(), s.end());
    vector<Point> ret(s.size() * 2);
    int sz = 0;
    for (int i = 0; i < s.size(); i++) {
        while (sz > 1 && sgn(cross(ret[sz - 1], s[i], ret[sz - 2])) <= 0) sz--;
        ret[sz++] = s[i];
    }
    int k = sz;
    for (int i = s.size() - 2; i >= 0; i--) {
        while (sz > 1 && sgn(cross(ret[sz - 1], s[i], ret[sz - 2])) <= 0) sz--;
        ret[sz++] = s[i];
    }
    ret.resize(sz - (s.size() > 1));
    return ret;
}
int cmp(const Point &a, const Point &b) {
    return sgn(a.x - b.x) < 0 || (sgn(a.x - b.x) == 0 && sgn(a.y - b.y) < 0);
}

Point l_intersection(const Line &a, const Line &b) {
    double s1 = det(a.t - a.s, b.s - a.s), s2 = det(a.t - a.s, b.t - a.s);
    return (b.s * s2 - b.t * s1) / (s2 - s1);
}
double rotatingCalipers(const vector<Point> &s) {
    int l = 0, r = 0, u = 0;
    Line now = Line(s[0], s[1]);
//    while (sgn(det(now.norm(), s[(l - 1 + s.size()) % s.size()] - s[l])) > 0) l = (l - 1 + s.size()) % s.size();
//    while (sgn(det(now.norm(), s[(r + 1 + s.size()) % s.size()] - s[r])) < 0) r = (r + 1 + s.size()) % s.size();
//    while (sgn(det(now.t - now.s, s[(u + 1 + s.size()) % s.size()] - s[u])) > 0) u = (u + 1 + s.size()) % s.size();
    double ans = 1e18;
    vector<Point> ansv;
    for (int i = 0; i < s.size(); i++) {
        now = Line(s[i], s[(i + 1) % s.size()]);
        while (sgn(det(now.norm(), s[(l - 1 + s.size()) % s.size()] - s[l])) > 0) l = (l - 1 + s.size()) % s.size();
        while (sgn(det(now.norm(), s[(l + 1 + s.size()) % s.size()] - s[l])) > 0) l = (l + 1 + s.size()) % s.size();
        if(r == i) r = (r + 1) % s.size();
        while (sgn(det(now.norm(), s[(r + 1 + s.size()) % s.size()] - s[r])) < 0) r = (r + 1 + s.size()) % s.size();
        if(u == i) u = (u + 1) % s.size();
        while (sgn(det(now.t - now.s, s[(u + 1 + s.size()) % s.size()] - s[u])) > 0) u = (u + 1 + s.size()) % s.size();
        Point ld, lu, rd, ru;
        ld = l_intersection(now, Line(s[l], s[l] + now.norm()));
        lu = l_intersection(Line(s[u], s[u] + now.t - now.s), Line(s[l], s[l] + now.norm()));
        rd = l_intersection(now, Line(s[r], s[r] + now.norm()));
        ru = l_intersection(Line(s[u], s[u] + now.t - now.s), Line(s[r], s[r] + now.norm()));
//        cout << l << " " << r << " " << u << " " << i << endl;
//        cout << ld.x << " " << ld.y << " " << lu.x << " " << lu.y << " " << rd.x << " " << rd.y << " " << ru.x << " " << ru.y << endl;
        double area = abs(lu - ld) * abs(rd - ld);
//        if(area == 0) {
//            cout << l << " " << r << " " << u << " " << i << endl;
//            cout << s[l].x << " " << s[l].y << endl;
//            cout << s[r].x << " " << s[r].y << endl;
//            cout << s[u].x << " " << s[u].y << endl;
//            cout << s[i].x << " " << s[i].y << endl << endl << endl;
//            cout << ld.x << " " << ld.y << " " << lu.x << " " << lu.y << " " << rd.x << " " << rd.y << " " << ru.x << " " << ru.y << endl;

//        }
        if (area < ans) {
            ans = area;
            ansv.clear();
            ansv.push_back(ld);
            ansv.push_back(rd);
            ansv.push_back(ru);
            ansv.push_back(lu);
        }
    }
    cout << fixed << setprecision(5) << ans << endl;
    int k = 0;
    for (int i = 1; i < 4; i++) {
        if (sgn(ansv[k].y - ansv[i].y) != 0) {
            if (ansv[k].y > ansv[i].y) {
                k = i;
            }
        } else {
            if (ansv[k].x > ansv[i].x) {
                k = i;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
//        if(fabs(ansv[(k + i) % 4].x) < 1e-5) cout << "0.00000 ";
//        else cout << ansv[(k + i) % 4].x << " ";
//        if(fabs(ansv[(k + i) % 4].y) < 1e-5) cout << "0.00000\n";
//        else cout << ansv[(k + i) % 4].y << endl;
        cout << ansv[(k + i) % 4].x << " " << ansv[(k + i) % 4].y << endl;
    }
}

int n, m, a[N];
vector<Point> v;

void work() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        double x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    v = Convex_hull(v);
//    cout << v.size() << endl;
//    for(int i = 0; i < v.size(); i++) {
//        cout << fixed << setprecision(5) << v[i].x << " " << v[i].y << endl;
//    }
//    cout << endl;
    rotatingCalipers(v);
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