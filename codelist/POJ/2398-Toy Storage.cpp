//
// Created by onglu on 2022/4/12.
//

#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
struct Point {
    int x, y;
    Point() = default;
    Point(const int &a, const int &b) : x(a), y(b) {}
};
Point operator+(const Point &a, const Point &b) { return {a.x + b.x , a.y + b.y}; }
Point operator-(const Point &a, const Point &b) { return {a.x - b.x , a.y - b.y}; }
Point operator*(const Point &a, const int &b) { return {a.x * b , a.y * b}; }
Point operator/(const Point &a, const int &b) { return {a.x / b , a.y / b}; }
int dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
int det(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}
struct Line {
    Point s, t;
    Line() = default;
    Line(const Point &a, const Point &b) : s(a), t(b) {}
};


int n, m, yu, yd;
pair<int, int> u[N];
vector<Point> v;
int id[N];

void work() {
    for(int i = 1; i <= n; i++) {
        cin >> u[i].first >> u[i].second;
    }
    sort(u + 1, u + 1 + n);
    v.clear();
    for(int i = 1; i <= m; i++) {
        id[i] = 0;
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    int left = 0;
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        Point U(u[i].first, yu);
        Point D(u[i].second, yd);
        for(int j = 0; j < m; j++) {
            if(det(U - D, v[j] - D) > 0) {
                cnt++;
            }
        }
        id[cnt - left] += 1;
//        cout << i - 1 << ": " << cnt - left << endl;
        left = cnt;
    }
    id[m - left] += 1;
    cout << "Box" << endl;
    for(int i = 1; i <= m; i++) {
        if(id[i] > 0) {
            cout << i << ": " << id[i] << endl;
        }
    }

}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q,w,e,r;
    while(cin >> n) {
        if(n == 0) break;
        cin >> m >> q >> yu >> e >> yd;
        work();
    }
    return 0;
}