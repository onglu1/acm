//
// Created by onglu on 2022/6/24.
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
const int N = 4e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, a[N], mod;
int sum[N], mulsum[N], lzt[N], lzt2[N];
void update(int rt) {
    sum[rt] = (sum[lson] + sum[rson]) % mod;
    mulsum[rt] = ((mulsum[lson] + mulsum[rson]) % mod + sum[lson] * sum[rson] % mod) % mod;
}
void build(int l, int r, int rt) {
    lzt[rt] = 0;
    lzt2[rt] = 1;
    if(l == r) {
        sum[rt] = a[l];
        mulsum[rt] = 0;
        return;
    }
    build(l, Mid, lson);
    build(Mid + 1, r, rson);
    update(rt);
}
void pushdown(int l, int r, int rt) {
    if(lzt[rt] == 0 && lzt2[rt] == 1) return ;
    (lzt[lson] *= lzt2[rt]) %= mod; (lzt[rson] *= lzt2[rt]) %= mod;
    (lzt2[lson] *= lzt2[rt]) %= mod; (lzt2[rson] *= lzt2[rt]) %= mod;
    (sum[lson] *= lzt2[rt]) %= mod; (sum[rson] *= lzt2[rt]) %= mod;
    (mulsum[lson] *= lzt2[rt] * lzt2[rt] % mod) %= mod; (mulsum[rson] *= lzt2[rt] * lzt2[rt] % mod) %= mod;
    lzt2[rt] = 1;
    (lzt[lson] += lzt[rt]) %= mod; (lzt[rson] += lzt[rt]) %= mod;
    int ll = (Mid - l + 1); ll = (ll - 1) * ll / 2 % mod;
    int rr = (r - Mid); rr = (rr - 1) * rr / 2 % mod;
    (mulsum[lson] += lzt[rt] * lzt[rt] % mod * ll % mod + sum[lson] * (Mid - l + 1 - 1) % mod * lzt[rt] % mod) %= mod;
    (mulsum[rson] += lzt[rt] * lzt[rt] % mod * rr % mod + sum[rson] * (r - Mid - 1) % mod * lzt[rt] % mod) %= mod;
    (sum[lson] += (Mid - l + 1) * lzt[rt] % mod) %= mod;
    (sum[rson] += (r - Mid) * lzt[rt] % mod) %= mod;
    lzt[rt] = 0;
}
void modify(int l, int r, int L, int R, int rt, int x) {
    if(L <= l && r <= R) {
        int ll = (r - l + 1); ll = (ll - 1) * ll / 2 % mod;
        // cout << l << " " << r << " " << ll << " " << ll * x % mod * x % mod + sum[rt] * (r - l + 1) % mod * x % mod << endl;
        (mulsum[rt] += ll * x % mod * x % mod + sum[rt] * (r - l + 1 - 1) % mod * x % mod) %= mod;
        (sum[rt] += (r - l + 1) * x) %= mod;
        (lzt[rt] += x) %= mod;
        return ;
    }
    pushdown(l, r, rt);
    if(L <= Mid) modify(l, Mid, L, R, lson, x);
    if(Mid <  R) modify(Mid + 1, r, L, R, rson, x);
    update(rt);
}

void mul(int l, int r, int L, int R, int rt, int x) {
    if(L <= l && r <= R) {
        (mulsum[rt] *= x * x % mod) %= mod;
        (sum[rt] *= x) %= mod;
        (lzt[rt] *= x) %= mod;
        (lzt2[rt] *= x) %= mod;
        return ;
    }
    pushdown(l, r, rt);
    if(L <= Mid) mul(l, Mid, L, R, lson, x);
    if(Mid <  R) mul(Mid + 1, r, L, R, rson, x);
    update(rt);
}
pair<int, int> query(int l, int r, int L, int R, int rt) {
    if(L <= l && r <= R) return {sum[rt], mulsum[rt]};
    pushdown(l, r, rt);
    if(R <= Mid) return query(l, Mid, L, R, lson);
    else if(Mid < L) return query(Mid + 1, r, L, R, rson);
    else {
        auto x1 = query(l, Mid, L, R, lson);
        auto x2 = query(Mid + 1, r, L, R, rson);
        return {(x1.first + x2.first) % mod, ((x1.second + x2.second) % mod + x1.first * x2.first % mod) % mod};
    }
}
void mul(int l, int r, int x) {
    mul(1, n, l, r, 1, x);
}
void modify(int l, int r, int x) {
    modify(1, n, l, r, 1, x);
}
pair<int, int> query(int l, int r) {
    return query(1, n, l, r, 1);
}
void work() {
    cin >> n >> m >> mod;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 1);
    while(m--) {
        int opt;
        cin >> opt;
        if(opt == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            x %= mod;
            mul(l, r, x);
        } else if(opt == 1){
            int l, r, x;
            cin >> l >> r >> x;
            x %= mod;
            modify(l, r, x);
        } else if(opt == 3) {
            int l, r;
            cin >> l >> r;
            cout << query(l, r).second << endl;
        }
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