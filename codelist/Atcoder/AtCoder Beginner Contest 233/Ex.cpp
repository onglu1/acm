#include <bits/stdc++.h>

#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)

using namespace std;
const int N = 5e5 + 2;
int n;
vector<pair<int, int> > a;
vector<int> v[2 * N];
void add(int x, int y) {
    x += N; y += N;
    for( ; y < 2 * N; y += y & -y)
        v[y].push_back(x);
}
int get(int y, int lx, int rx) {
    y += N; lx += N; rx += N;
    if(y <= 0) y = 1;
    if(lx <= 0) lx = 1;
    if(rx >= 2 * N) rx = 2 * N - 1;
    int ans = 0;
    for( ; y; y -= y & -y) {
        ans += upper_bound(v[y].begin(), v[y].end(), rx) - lower_bound(v[y].begin(), v[y].end(), lx);
    }
    return ans;
}
int query(int lx, int ly, int rx, int ry) {
    return get(ry, lx, rx) - get(ly - 1, lx, rx);
}
signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x + y, x - y});
    }
    sort(a.begin(), a.end());
    for(auto p : a) {
        add(p.first, p.second);
    }
//    cout << "cnt : ";
//    cout << query(3 + 5 - 2, 3 - 5 - 2, 3 + 5 + 2, 3 - 5 + 2) << endl;
//    cout << query(3 + 5 - 1, 3 - 5 - 1, 3 + 5 + 1, 3 - 5 + 1) << endl;
    int q;
    cin >> q;
    while(q--) {
        int a, b, k;
        cin >> a >> b >> k;
        int l = 0, r = 200009;
        while(l <= r) {
            if(query(a + b - Mid, a - b - Mid, a + b + Mid, a - b + Mid) < k) l = Mid + 1;
            else r = Mid - 1;
        }
        cout << l << endl;
    }
    return 0;
}
