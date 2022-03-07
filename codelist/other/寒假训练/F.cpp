#include <bits/stdc++.h>
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 1e5 + 1009;
const int mod = 1e9 + 7;
struct Mat {
    int g[2][2];
    Mat() {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                if(i == j) g[i][j] = 1;
                else g[i][j] = 0;
            }
        }
    }
} base, pw[50], p = Mat();
Mat operator*(const Mat &a, const Mat &b) {
    Mat m = Mat();
    memset(m.g, 0, sizeof(m.g));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                m.g[i][j] += 1ll * a.g[i][k] * b.g[k][j] % mod;
                if(m.g[i][j] >= mod) m.g[i][j] -= mod;
            }
        }
    }
    return m;
}
Mat operator+(const Mat &a, const Mat &b) {
    Mat m = Mat();
    memset(m.g, 0, sizeof(m.g));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            m.g[i][j] = a.g[i][j] + b.g[i][j];
            if(m.g[i][j] >= mod) m.g[i][j] -= mod;
        }
    }
    return m;
}
Mat Pow(int p) {
    Mat ans = Mat();
    for(int i = 0; i < 32; i++) {
        if(p >> i & 1) {
            ans = ans * pw[i];
        }
    }
    return ans;
}
int n, m, a[N];
Mat tree[N * 4], lzt[N * 4];
void update(int rt) {
    tree[rt] = tree[lson] + tree[rson];
}
void build(int l, int r, int rt) {
    lzt[rt] = Mat();
    if(l == r) {
        tree[rt] = Pow(a[l]);
        return ;
    }
    build(l, Mid, lson);
    build(Mid + 1, r, rson);
    update(rt);
}
void pushdown(int rt) {
    int f = 1;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            if(lzt[rt].g[i][j] != p.g[i][j]) {
                f = 0;
            }
        }
    }
    if(f == 1) return ;
    tree[lson] = tree[lson] * lzt[rt]; lzt[lson] = lzt[lson] * lzt[rt];
    tree[rson] = tree[rson] * lzt[rt]; lzt[rson] = lzt[rson] * lzt[rt];
    lzt[rt] = Mat();
}
void modify(int l, int r, int L, int R, int x, int rt) {
    if(L <= l && r <= R) {
        lzt[rt] = lzt[rt] * Pow(x);
        tree[rt] = tree[rt] * Pow(x);
        return ;
    }
    pushdown(rt);
    if(L <= Mid) modify(l, Mid, L, R, x, lson);
    if(Mid <  R) modify(Mid + 1, r, L, R, x, rson);
    update(rt);
}
Mat query(int l, int r, int L, int R, int rt) {
    if(L <= l && r <= R) return tree[rt];
    pushdown(rt);
    if(R <= Mid) return query(l, Mid, L, R, lson);
    else if(L > Mid) return query(Mid + 1, r, L, R, rson);
    else return query(l, Mid, L, R, lson) + query(Mid + 1, r, L, R, rson);
}
signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    base.g[0][0] = 0; base.g[0][1] = 1;
    base.g[1][0] = 1; base.g[1][1] = 1;
    pw[0] = base;
    for(int i = 1; i < 50; i++) {
        pw[i] = pw[i - 1] * pw[i - 1];
    }
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 1);
    for(int i = 1; i <= m; i++) {
        int opt, l, r, x;
        cin >> opt >> l >> r;
        if(opt == 1) {
            cin >> x;
            modify(1, n, l, r, x, 1);
        } else {
            Mat ans = query(1, n, l, r, 1);
            int t = ans.g[0][1];
            if(t >= mod) t -= mod;
            cout << t << endl;
        }
    }
    return 0;
}