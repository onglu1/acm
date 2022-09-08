//
// Created by onglu on 2022/5/18.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
#define int long long
using namespace std;
const int N = 2e6 + 1009;
const int mod = 998244353;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, a[N];
int tree[N], ok[N], lzt[N];
void update(int rt) {
    tree[rt] = (tree[lson] + tree[rson]) % mod;
    ok[rt] = ok[lson] & ok[rson];
}
void build(int l, int r, int rt) {
    ok[rt] = 0;
    lzt[rt] = 1;
    if(l == r) {
        tree[rt] = a[l];
        if(a[l] == (a[l] & -a[l])) {
            ok[rt] = 1;
        }
        return ;
    }
    build(l, Mid, lson);
    build(Mid + 1, r, rson);
    update(rt);
}
void pushdown(int rt) {
    if(lzt[rt] == 1) return ;
    (lzt[lson] *= lzt[rt]) %= mod;
    (tree[lson] *= lzt[rt]) %= mod;
    (lzt[rson] *= lzt[rt]) %= mod;
    (tree[rson] *= lzt[rt]) %= mod;
    lzt[rt] = 1;
}
void modify(int l, int r, int L, int R, int rt) {
    // cerr << l << " " << r << endl;
    if(l == r) {
        if(ok[rt]) {
            tree[rt] = tree[rt] * 2 % mod;
        } else {
            tree[rt] += tree[rt] & -tree[rt];
            if(tree[rt] == (tree[rt] & -tree[rt])) {
                ok[rt] = 1;
                tree[rt] %= mod;
            }
        }
        return ;
    }
    if(ok[rt] && L <= l && r <= R) {
        (lzt[rt] *= 2) %= mod;
        (tree[rt] *= 2) %= mod;
        return ;
    }
    pushdown(rt);
    if(L <= Mid) modify(l, Mid, L, R, lson);
    if(Mid <  R) modify(Mid + 1, r, L, R, rson);
    update(rt);
}
int query(int l, int r, int L, int R, int rt) {
    // cerr << l << " " << r << endl;
    if(L <= l && r <= R) return tree[rt];
    pushdown(rt);
    int ans = 0;
    if(L <= Mid) ans = query(l, Mid, L, R, lson);
    if(Mid <  R) ans = (ans + query(Mid + 1, r, L, R, rson)) % mod;
    return ans;
}
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 1);
    int q;
    cin >> q;
    while(q--) {
        int opt, l, r;
        cin >> opt >> l >> r;
        if(opt == 1) {
            modify(1, n, l, r, 1);
        } else {
            cout << query(1, n, l, r, 1) << endl;
        }
        // cerr << endl;
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
    cin >> Case;
    while(Case--) work();
    return 0;
}