//
// Created by onglu on 2022/5/11.
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
const int N = 2e5 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, h[N], pos[N];
struct node {
    int h, a, id;
} v[N];
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        v[i] = {h[i], x - y, i};
    }
    int q;
    cin >> q;
    for(int i = n + 1; i <= n + q; i++) {
        int x, y;
        cin >> h[i] >> x >> y;
        v[i] = {h[i],  x - y, i};
    }
    sort(v + 1, v + 1 + n + q, [](const node &a, const node &b) {
        if(a.a > 0 && b.a > 0) return a.h - a.a > b.h - b.a;
        else if(a.a <= 0 && b.a <= 0) return a.h < b.h;
        else return a.a < b.a;
    });
//    for(int i = 1; i <= n + q; i++) {
//        cout << v[i].h << " " << v[i].a << endl;
//    }
    for(int i = 1; i <= n + q; i++) pos[v[i].id] = i;
    for(int i = 1; i <= n + q; i++) v[i].id = 0;
    for(int i = 1; i < n; i++) v[pos[i]].id = 1;
    for(int i = n; i <= n + q; i++) {
        v[pos[i]].id = 1;
        int ini = -0x3f3f3f3f3f3f3f3f, now = 0;
        for(int j = 1; j <= n + q; j++) if(v[j].id) {
            if(ini < v[j].h + now) ini = v[j].h + now;
            now += v[j].a;
        }
        cout << ini << endl;
    }

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