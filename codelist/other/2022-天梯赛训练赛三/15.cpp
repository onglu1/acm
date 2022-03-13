//
// Created by onglu on 2022/3/12.
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
int n, m;
struct Point {
    double x, y;
} a[N];
Point operator-(const Point &a, const Point &b) {return {a.x - b.x, a.y - b.y};}
Point operator+(const Point &a, const Point &b) {return {a.x + b.x, a.y + b.y};}
double det(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}
double dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
Point rot(const Point &a, double theta){ return {a.x * cos(theta) - a.y * sin(theta), a.x * sin(theta) + a.y * cos(theta)}; }
void work() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lf %lf", &a[i].x, &a[i].y);
    }
    int ans = 1ll << 61;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            a[j] = a[j] - a[i];
        }
        for(int j = 1; j <= n; j++) {

        }

    }
    printf("%.3f\n", ans / 2.0);
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    work();
    return 0;
}