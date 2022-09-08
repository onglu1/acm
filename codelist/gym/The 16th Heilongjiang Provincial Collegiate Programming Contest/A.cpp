//
// Created by onglu on 2022/5/11.
//

#include <bits/stdc++.h>
#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
using namespace std;
const int N = 2e6 + 1009;
int n, m, a[N];
int tree[N], tor[N];
void update(int rt) {
    tree[rt] = max(tree[lson], tree[rson]);
    tor[rt] = tor[lson] | tor[rson];
}
void build(int l, int r, int rt) {
    if(l == r) {
        return (void) (tree[rt] = tor[rt] = a[l]);
    }
    build(l, Mid, lson);
    build(Mid + 1, r, rson);
    update(rt);
}
void modify(int l, int r, int L, int R, int rt, int x) {
//    cerr << "m  " << rt << endl;
    if((tor[rt] & x) == tor[rt]) return ;
    if(l == r) {
        tree[rt] &= x;
        tor[rt] &= x;
        return ;
    }
    if(L <= Mid) modify(l, Mid, L, R, lson, x);
    if(Mid <  R) modify(Mid + 1, r, L, R, rson, x);
    update(rt);
}
void change(int l, int r, int rt, int pos, int x) {
//    cerr << "c  " << rt << endl;
    if(l == r) {
        tree[rt] = tor[rt] = x;
        return ;
    }
    if(pos <= Mid) change(l, Mid, lson, pos, x);
    else change(Mid + 1, r, rson, pos, x);
    update(rt);
}
int query(int l, int r, int L, int R, int rt) {
//    cerr << "q  " << rt << " " << l << " " << r << " " << L << " " << R << " " << Mid << endl;
    if(L <= l && r <= R) return tree[rt];
    if(R <= Mid) {
        return query(l, Mid, L, R, lson);
    } else if(Mid < L) {
        return query(Mid + 1, r, L, R, rson);
    } else {
        return max(query(l, Mid, L, R, lson), query(Mid + 1, r, L, R, rson));
    }
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
//    read(n); read(m);
    for(int i = 1; i <= n; i++) cin >> a[i]; //read(a[i]);
    build(1, n, 1);
    for(int i = 1; i <= m; i++) {
        char c[5];
        cin >> c;
//        scanf("%s", c);
        if(c[0] == 'A') {
            int l, r, v;
            cin >> l >> r >> v;
//            read(l); read(r); read(v);
            modify(1, n, l, r, 1, v);
        } else if(c[0] == 'U') {
            int x, v;
            cin >> x >> v;
//            read(x); read(v);
            change(1, n, 1, x, v);
        } else {
            int l, r;
            cin >> l >> r;
//            read(l); read(r);
            cout << query(1, n, l, r, 1) << endl;
//            printf("%d\n", query(1, n, l, r, 1));
        }
    }
    return 0;
}