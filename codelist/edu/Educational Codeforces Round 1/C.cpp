//
// Created by onglu on 2022/4/24.
//

#include <bits/stdc++.h>
#define int long long
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
struct Point {
    int x, y;
    int quad() const {
        return y > 0 || (y == 0 && x > 0);
    }
    int len() const {
        return x * x + y * y;
    }
    Point(int x, int y) : x(x), y(y) {}
    Point() {}
};
int det(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

int dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
bool operator<(const Point &a, const Point &b) {
    if(a.quad() ^ b.quad()) return a.quad() > b.quad();
    else return det(a, b) > 0;
}
int n, m;
vector<pair<Point, int> > v;
int sgn(int x) {
    if(x == 0) return 0;
    else return x < 0 ? -1 : 1;
}
int check(Point a, Point b, Point c, Point d) {
    if(det(a, b) < 0) swap(a, b);
    if(det(c, d) < 0) swap(c, d);
//    cout << sgn(dot(a, b)) << " " << sgn(dot(c, d)) << endl;
    if(sgn(dot(a, b)) != sgn(dot(c, d))) return sgn(dot(c, d)) >= sgn(dot(a, b));
    if(sgn(dot(a, b)) == 0) return 1;
    if(sgn(dot(a, b)) > 0)
        return __int128(1) * dot(c, d) * dot(c, d) * a.len() * b.len() > __int128(1) * dot(a, b) * dot(a, b) * c.len() * d.len();
    else
        return __int128(1) * dot(c, d) * dot(c, d) * a.len() * b.len() < __int128(1) * dot(a, b) * dot(a, b) * c.len() * d.len();
}
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({Point(x, y), i});
    }
    std::sort(v.begin(), v.end());
    for(auto x : v) {
        cout << x.first.x << " " << x.first.y << " " << x.second << endl;
    }
    int p = 0;
//    cout << check(v[2].first, v[3].first, v[3].first, v[4].first) << endl;
    for(int i = 1; i < v.size(); i++) {
        if(check(v[p].first, v[(p + 1) % v.size()].first, v[i].first, v[(i + 1) % v.size()].first)) {
            p = i;
        }
    }
    cout << v[p].second << " " << v[(p + 1) % v.size()].second << endl;
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