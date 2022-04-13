//
// Created by onglu on 2022/4/12.
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
const double eps = 1e-10;
double rand_eps() {
    return ((double)rand() / RAND_MAX - 0.5) * eps;
}
struct Point {
    double x, y, z;
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
    double len() {
        return sqrt(x * x + y * y + z * z);
    }
    void shake() {
        x += rand_eps();
        y += rand_eps();
        z += rand_eps();
    }
};
Point operator+(const Point &a, const Point &b) { return {a.x + b.x, a.y + b.y, a.z + b.z}; }
Point operator-(const Point &a, const Point &b) { return {a.x - b.x, a.y - b.y, a.z - b.z}; }
Point operator*(const Point &a, const double &b) { return {a.x * b, a.y * b, a.z * b}; }
Point operator/(const Point &a, const double &b) { return {a.x / b, a.y / b, a.z / b}; }
double dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
Point det(const Point &a, const Point &b) {
    return {a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}
vector<Point> p;
struct Plane {
    int v[3];
    Plane(const int &a, const int &b, const int &c) : v{a, b, c} {}
    Point norm() {
        return det(p[v[0]] - p[v[1]], p[v[2]] - p[v[1]]);
    }
    int above(const Point &q) {
        return dot((q - p[v[0]]), norm()) >= 0;
    }
    double area() {
        return norm().len() / 2;
    }
};
int n;
vector<Plane> convex_hull_3d() {
    for(int i = 0; i < p.size(); i++) p[i].shake();
    vector<Plane> plane, tmp;
    vector<vector<int> > vis(n);
    for(int i = 0; i < n; i++)
        vis[i].resize(n);
    plane.emplace_back(0, 1, 2);
    plane.emplace_back(0, 2, 1);
    for(int i = 3; i < n; i++) {
        tmp = plane;
        plane.clear();
        for(auto t : tmp) {
            bool f = t.above(p[i]);
            if(!f) plane.push_back(t);
            for(int k = 0; k < 3; k++) {
                vis[t.v[k]][t.v[(k + 1) % 3]] = f;
            }
        }
        for(auto t : tmp) {
            for(int k = 0; k < 3; k++) {
                int a = t.v[k], b = t.v[(k + 1) % 3];
                if(vis[a][b] != vis[b][a] && vis[a][b]) {
                    plane.push_back(Plane{a, b, i});
                }
            }
        }
    }
    return plane;

}
void work() {
    srand(1230213);
    cin >> n;
    for(int i = 0; i < n; i++) {
        double x, y, z;
        cin >> x >> y >> z;
        p.push_back({x, y, z});
    }
    vector<Plane> convex = convex_hull_3d();
    double area = 0;
    for(auto x : convex) {
        area += x.area();
    }
    cout << fixed << setprecision(6) << area << endl;
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