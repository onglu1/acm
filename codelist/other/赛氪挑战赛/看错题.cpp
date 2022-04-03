#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
using namespace std;
const int N = 2e6 + 1009;
int n, m, a[N], siz[N], dth[N];
int ans = 0;
int build(int l, int r, int rt) {
    if(l == r) {
        siz[rt] = 1;
        dth[rt] = 1;
        ans += a[l];
        return a[l];
    }
    int val = build(l, Mid, lson) + build(Mid + 1, r, rson);
    dth[rt] = dth[lson] + 1;
    siz[rt] = siz[lson] + siz[rson];
    ans += siz[rt] * val;
    return val;
}
int modify(int l, int r, int L, int R, int rt, int x) {
    if(L <= l && r <= R) {
        ans += siz[rt] * ((1 << (dth[rt])) - 1) * x;
        return ((1 << (dth[rt] - 1))) * x;
    }
    int val = 0;
    if(L <= Mid) val += modify(l, Mid, L, R, lson, x);
    if(Mid <  R) val += modify(Mid + 1, r, L, R, rson, x);
    ans += siz[rt] * val;
    return val;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, n, 1);
    for(int i = 1; i <= m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        modify(1, n, l, r, 1, x);
        cout << ans << endl;
    }
    return 0;
}