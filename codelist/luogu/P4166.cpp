//
// Created by onglu on 2022/4/4.
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
int n, m;
struct Point {
    double x, y;
} ;
double dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
double det(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}
Point operator +(const Point &a, const Point &b) {return {a.x + b.x, a.y + b.y};}
Point operator -(const Point &a, const Point &b) {return {a.x - b.x, a.y - b.y};}
int cmp(const Point &a, const Point &b) {
    if(a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}
const double eps = 1e-11;
double sgn(double x) {
    if(fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}
vector<Point> v;
vector<Point> convex_hull(vector<Point> v) {
    std::sort(v.begin(), v.end(), cmp);
    vector<Point> t;
    for(int i = 0; i < v.size(); i++) {
        if(i == 0 || dot(v[i] - v[i - 1], v[i] - v[i - 1]) != 0) {
            t.push_back(v[i]);
        }
    }
//    for(int i = 1; i < t. size(); i++)
    vector<Point> g(t.size() * 2);
    int s = 0;
    for(int i = 0; i < t.size(); i++) {
        while(s > 1 && sgn(det(g[s - 1] - g[s - 2], t[i] - g[s - 2])) < 0) {
            s--;
        }
        g[s++] = t[i];
    }
    for(int i = t.size() - 2; i >= 0; i--) {
        while(s > 1 && sgn(det(g[s - 1] - g[s - 2], t[i] - g[s - 2])) < 0) {
            s--;
        }
        g[s++] = t[i];
    }
    g.resize(s - (t.size() > 1));
//    cout << g.size() << endl;
    return g;

}
#define nxt(i, j) ((i + 1) % j.size())
void work() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        double x, y;
        scanf("%lf%lf", &x, &y);
        v.push_back({x, y});
    }
    v = convex_hull(v);
    if(v.size() <= 3) {
        printf("0.000\n");
        return ;
    }
//    for(auto x : v) {
//        cout << x.x << " " << x.y << endl;
//    }
    double ans = 0;
    for(int i = 0; i < v.size(); i++) {
        int d = i, u = nxt(i, v);
        for(int j = nxt(i, v); j != i; j = nxt(j, v)) {
            Point l = v[j] - v[i];
            while(sgn(det(l, v[nxt(u, v)] - v[u])) > 0) u = nxt(u, v);
            while(sgn(det(l, v[nxt(d, v)] - v[d])) < 0) d = nxt(d, v);
            ans = max(ans, (abs(det(l, v[d] - v[i])) + abs(det(l, v[u] - v[i]))) / 2);
        }
    }
    printf("%.3f\n", ans);
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int Case = 1;
//    cin >> Case;
    while (Case--) work();
    return 0;
}