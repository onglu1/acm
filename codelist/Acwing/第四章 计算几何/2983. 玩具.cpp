//
// Created by onglu on 2022/3/18.
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
//const int N = 309
struct Point {
    int x, y;
};
Point operator+(const Point &a, const Point &b) {return {a.x + b.x, a.y + b.y};}
Point operator-(const Point &a, const Point &b) {return {a.x - b.x, a.y - b.y};}
int dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
int det(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}
Point a[N];
int n, m, cnt[N], lx, ly, rx, ry;
Point u[N], d[N];
void work() {
    for(int i = 1; i <= n; i++) {
        int p, q;
        cin >> p >> q;
        u[i] = {p, ly};
        d[i] = {q, ry};
    }
    u[++n] = {rx, ly};
    d[n] = {rx, ry};
    for(int i = 1; i <= m; i++) {
        cin >> a[i].x >> a[i].y;
    }
    memset(cnt, 0, sizeof(int) * (n + 10));
    for(int i = 1; i <= m; i++) {
        int l = 1, r = n;
        while(l <= r) {
            if(det(a[i] - d[Mid], u[Mid] - d[Mid]) <= 0) r = Mid - 1;
            else l = Mid + 1;
        }
        cnt[l]++;
    }
    int now = 0;
    for(int i = 1; i <= n; i++) {
        cout << i - 1 << ": " << cnt[i] << endl;
    }
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n) {
        if(n == 0) break;
        static int cnt = 0;
        cin >> m >> lx >> ly >> rx >> ry;
        cnt++;
        if(cnt != 1) cout << endl;
        work();
    }
    return 0;
}