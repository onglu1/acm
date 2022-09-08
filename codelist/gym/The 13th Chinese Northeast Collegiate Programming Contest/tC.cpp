#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 1009;
struct Point {
    int x, y;
};
struct line {
    Point s, t;
};
int n;
line a[N];
istream &operator>>(istream &in, Point &p) {
    in >> p.x >> p.y;
    return in;
}
Point operator+(const Point &a, const Point &b) {
    return {a.x + b.x, a.y + b.y};
}
Point operator-(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}
int det(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}
int dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
pair<int, int> format(int X, int Y) {
    if(X < 0 && Y < 0) X = -X, Y = -Y;
    if(X < 0 && Y > 0) X = -X, Y = -Y;
    if(X == 0) Y = 1;
    else if(Y == 0) X = 1;
    else {
        int g = __gcd(abs(X), abs(Y));
        X /= g; Y /= g;
    }
    return {X, Y};
}
map<pair<int, int>, int> M;
map<pair<int, int>, map<int, int> > G;
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].s >> a[i].t;
    }
    M.clear(); G.clear();
    Point O = {0, 0};
    for(int i = 1; i <= n; i++) {
        int X = a[i].t.x - a[i].s.x;
        int Y = a[i].t.y - a[i].s.y;
        auto p = format(X, Y);
        Point ns;
        ns.x = a[i].s.x + p.first;
        ns.y = a[i].s.y + p.second;
        M[p] += 1;
        G[p][det(a[i].s - O, (a[i].s + ns) - O)] += 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int X = a[i].t.x - a[i].s.x;
        int Y = a[i].t.y - a[i].s.y;
        auto p = format(X, Y);
        Point ns;
        ns.x = a[i].s.x + p.first;
        ns.y = a[i].s.y + p.second;
        ans += n - M[p];
        ans += G[p][det(a[i].s - O, (a[i].s + ns) - O)] - 1;
    }
    ans /= 2;
    cout << ans << endl;
}
signed main()
{
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);cin.tie(0);
    int Case ;
    cin >> Case;
    while(Case--) work();
    return 0;
}