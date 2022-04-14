//
// Created by onglu on 2022/4/11.
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
    int x, y;
};
struct Cir {
    Point o;
    int r;
} ;
Cir c[N];
Point operator+(const Point &a, const Point &b) { return {a.x + b.x, a.y + b.y}; }
Point operator-(const Point &a, const Point &b) { return {a.x - b.x, a.y - b.y}; }
Point operator*(const Point &a, const int &b) { return {a.x * b, a.y * b}; }
Point operator/(const Point &a, const int &b) { return {a.x / b, a.y / b}; }
int dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> c[i].o.x;
    }
    for(int i = 1; i <= n; i++) {
        cin >> c[i].o.y;
    }
    for(int i = 1; i <= n; i++) {
        cin >> c[i].r;
    }
    int cnt = 0;
    Point a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    for(int i = 1; i <= n; i++) {
        int f1 = 0, f2 = 0;
        if(dot(a - c[i].o, a - c[i].o) < c[i].r * c[i].r) {
            f1 = 1;
        }
        if(dot(b - c[i].o, b - c[i].o) < c[i].r * c[i].r) {
            f2 = 1;
        }
        cnt += (f1 ^ f2);
    }
    cout << cnt << endl;

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