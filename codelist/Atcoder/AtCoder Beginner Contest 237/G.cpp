//
// Created by onglu on 2022/2/26.
//

#include <bits/stdc++.h>

#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N], tree[N], lzt[N];
int X, posX;
void update(int rt) {
    tree[rt] = tree[lson] + tree[rson];
}
void pushdown(int l, int r, int rt) {
    if(lzt[rt] == -1) return ;
    lzt[lson] = lzt[rson] = lzt[rt];
    tree[lson] = lzt[rt] * (Mid - l + 1);
    tree[rson] = lzt[rt] * (r - Mid);
    lzt[rt] = -1;
}
void build(int l, int r, int rt) {
    lzt[rt] = -1;
    if(l == r) {
        tree[rt] = a[l];
        return ;
    }
    build(l, Mid, lson); build(Mid + 1, r, rson);
    update(rt);
}
int query(int l, int r, int L, int R, int rt) {
    if(l > R || r < L) return 0;
    if(L <= l && r <= R) return tree[rt];
    pushdown(l, r, rt);
    return query(l, Mid, L, R, lson) + query(Mid + 1, r, L, R, rson);
}
void modify(int l, int r, int L, int R, int x, int rt) {
    if(l > R || r < L) return ;
    if(L <= l && r <= R) {
        lzt[rt] = x;
        tree[rt] = lzt[rt] * (r - l + 1);
        return ;
    }
    pushdown(l, r, rt);
    modify(l, Mid, L, R, x, lson);
    modify(Mid + 1, r, L, R, x, rson);
    update(rt);
}
void work() {
    cin >> n >> m >> X;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == X) posX = i;
        a[i] = a[i] > X;
    }

    build(1, n, 1);

    for(int i = 1; i <= m; i++) {
        int opt, l, r;
        cin >> opt >> l >> r;
        int cnt = query(1, n, l, r, 1);
        if(opt == 1) {
            if(l <= posX && posX <= r) {
                posX = r - cnt;
            }
            modify(1, n, l, r - cnt, 0, 1);
            modify(1, n, r - cnt + 1, r, 1, 1);

        } else {
            if(l <= posX && posX <= r) {
                posX = l + cnt;
            }
            modify(1, n, l, l + cnt - 1, 1, 1);
            modify(1, n, l + cnt, r, 0, 1);
        }
//        cout << posX << endl;
    }
    cout << posX << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
    while (Case--) work();
    return 0;
}
/*
 * 只关心大于x和小于x的两种数就行了
 * 那就变成区间查询，区间修改
 */