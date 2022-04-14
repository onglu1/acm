
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
const int N = 2e6 + 1009;
const double eps = 1e-9;
int sgn(double x) {
    if(-eps < x && x < eps) return 0;
    else return x > 0 ? 1 : -1;
}
struct Point {
    double x, y;
    int quad() const {return sgn(y) == 1 || (sgn(y) == 0 && sgn(x) >= 0);}
    Point(double a, double b) : x(a), y(b) {}
};
Point operator-(const Point &a, const Point &b) {return {a.x - b.x, a.y - b.y};}
Point operator+(const Point &a, const Point &b) {return {a.x + b.x, a.y + b.y};}
Point operator*(const Point &a, double b) {return {a.x * b, a.y * b};}
Point operator*(double b, const Point &a) {return {a.x * b, a.y * b};}
Point operator/(double b, const Point &a) {return {a.x / b, a.y / b};}
Point operator/(const Point &a, double b) {return {a.x / b, a.y / b};}
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
vector<Point> half_intersection(vector<Line> &l) {
    sort(l.begin(), l.end());
    deque<Line> q;
//    for(auto tt : l) {
//        printf("Segment  %.2f %.2f %.2f %.2f\n", tt.s.x, tt.s.y, tt.t.x, tt.t.y);
//    }
//    printf("\n\n\n");
    for(int i = 0; i < l.size(); i++) {
        if(i && sameDir(l[i], l[i - 1])) {
            continue;
        }
        while(q.size() > 1 && !check(q[q.size() - 2], q[q.size() - 1], l[i])) q.pop_back();
        while(q.size() > 1 && !check(q[1], q[0], l[i])) q.pop_front();
        q.push_back(l[i]);
        static int qq = 0;
        qq++;
//        printf("%d\n", qq);
//        for(auto tt : q) {
//            printf("Segment %.2f %.2f %.2f %.2f\n", tt.s.x, tt.s.y, tt.t.x, tt.t.y);
//        }
//        printf("\n\n");
    }
    while(q.size() > 2 && !check(q[q.size() - 2], q[q.size() - 1], q[0])) q.pop_back();
    while(q.size() > 2 && !check(q[1], q[0], q[q.size() - 1])) q.pop_front();
//    for(auto tt : q) {
//        printf("Segment %.2f %.2f %.2f %.2f\n", tt.s.x, tt.s.y, tt.t.x, tt.t.y);
//    }
    vector<Point> ret;
    for (int i = 0; i < q.size(); i++) ret.push_back(l_intersection(q[i], q[(i + 1) % q.size()]));
    return ret;
}
int n, m;
vector<int> v, u, w;
int getup(int x, int y, int z, Line &l) {
    if(x == 0 && y == 0) {
        if(z <= 0) return 0;
        else return 1;
    }
    if(x == 0) {
        if(y > 0)
            l = Line(Point(0, 1.0 * -z / y), Point(1, 1.0 * -z / y));
        else
            l = Line(Point(1, 1.0 * -z / y), Point(0, 1.0 * -z / y));
        return 2;
    }
    if(y == 0) {
        if(x > 0)
            l = Line(Point(1.0 * -z / x, 1), Point(1.0 * -z / x, 0));
        else
            l = Line(Point(1.0 * -z / x, 0), Point(1.0 * -z / x, 1));
        return 2;
    }
    Point A = Point(0, 1.0 * -z / y);
    Point B = Point(1.0 * -z / x, 0);
    if(z > 0) {
        l = Line(A, B).include(Point(0, 0)) ? Line(A, B) : Line(B, A);
    } else if(z < 0) {
        l = Line(A, B).include(Point(0, 0)) ? Line(B, A) : Line(A, B);
    } else {
        A = Point(0, 0);
        B = Point(y, -x);
        l = Line(A, B);
    }
    return 2;
}
const double INF = 1e9;
int check(int x) {
    vector<Line> t;
    for(int i = 0; i < n; i++) if(i != x) {
            Line l = Line(Point(0, 0), Point(0, 0));
            int a, b, c;
            a = (v[x] - v[i]) * u[i] * u[x] * w[i] * w[x];
            b = (u[x] - u[i]) * v[i] * v[x] * w[i] * w[x];
            c = (w[x] - w[i]) * v[i] * v[x] * u[i] * u[x];
//        printf("%f %f %f\n", a, b, c);
            if(a <= 0 && b <= 0 && c <= 0) return false;
            int result = getup(a, b, c, l);
            if(result == 0) return false;
            if(result == 1) continue;
            l.t = l.s + 5 * (l.t - l.s);
            l.s = l.t - 2 * (l.t - l.s);
            t.push_back(l);
        }
    t.push_back(Line(Point(0, 0), Point(INF, 0)));
    t.push_back(Line(Point(INF, 0), Point(INF, INF)));
    t.push_back(Line(Point(INF, INF), Point(0, INF)));
    t.push_back(Line(Point(0, INF), Point(0, 0)));
//    for(auto tt : t) {
//        printf("Segment  %.2f %.2f %.2f %.2f\n", tt.s.x, tt.s.y, tt.t.x, tt.t.y);
//    }
//    printf("\n\n\n");
    vector<Point> ans = half_intersection(t);
    double area = 0;
    for(int i = 0; i < ans.size(); i++) {
//        printf("%.2f %.2f\n", ans[i].x, ans[i].y);
//        printf("%.2f\n", det(ans[i], ans[(i + 1) % ans.size()]));
        area += det(ans[i], ans[(i + 1) % ans.size()]);
    }
//    printf("%.2f\n", area);
    return sgn(area) != 0;
}
void work() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back(x);
        u.push_back(y);
        w.push_back(z);
    }
//    check(6);
    for(int i = 0; i < n; i++) {
        cout << (check(i) ? "Yes" : "No") << endl;
    }

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