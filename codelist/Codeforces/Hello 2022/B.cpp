#include <bits/stdc++.h>
#define int long long
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)

using namespace std;
int n, m;
void work() {
    cin >> n;
    int l, r, cl, cr;
    int cfill = (1ll << 60) - 1;
    cin >> l >> r >> cfill;
    cl = cr = cfill;
    cout << cfill << endl;
    for(int i = 2; i <= n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        if(x < l) cl = c, cfill = (1ll << 60) - 1, l = x;
        else if(x == l) cl = min(cl, c);
        if(y > r) cr = c, cfill = (1ll << 60) - 1, r = y;
        else if(y == r) cr = min(cr, c);
        if(l == x && r == y) cfill = min(cfill, c);
        cout << min(cl + cr, cfill) << endl;
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case;
    cin >> Case;
    while (Case--) work();
    return 0;
}
/*
 * 20 42
 * 42 42
 * 4 13 11 256 271 271
 */