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
int n, m, a[N];
int tree[N], lzt[N];
void update(int rt) {
    tree[rt] = min(tree[lson], tree[rson]);
}
void build(int l, int r, int rt) {
    lzt[rt] = 0;
    if(l == r) {
        tree[rt] = a[l];
        return;
    }
    build(l, Mid, lson);
    build(Mid + 1, r, rson);
    update(rt);
}
void pushdown(int rt) {
    if(lzt[rt] == 0) return ;
    lzt[lson] += lzt[rt]; lzt[rson] += lzt[rt];
    tree[lson] += lzt[rt]; tree[rson] += lzt[rt];
    lzt[rt] = 0;
}
void modify(int l, int r, int L, int R, int rt, int x) {
    if(L <= l && r <= R) {
        lzt[rt] += x;
        tree[rt] += x;
        return ;
    }
    pushdown(rt);
    if(L <= Mid) modify(l, Mid, L, R, lson, x);
    if(Mid <  R) modify(Mid + 1, r, L, R, rson, x);
    update(rt);
}
int query(int l, int r, int L, int R, int rt) {
    if(L <= l && r <= R) return tree[rt];
    pushdown(rt);
    if(R <= Mid) return query(l, Mid, L, R, lson);
    else if(Mid < L) return query(Mid + 1, r, L, R, rson);
    else return min(query(l, Mid, L, R, lson), query(Mid + 1, r, L, R, rson));
}
void modify(int l, int r, int x) {
    modify(1, n, l, r, 1, x);
}
int query(int l, int r) {
    return query(1, n, l, r, 1);
}
void work() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 1);
    for (int i = 1; i <= m; i++) {
        int l, r, d;
        cin >> d >> l >> r;
        if (query(l, r) < d) {
            cout << -1 << endl;
            cout << i << endl;
            return ;
        }
        modify(l, r, -d);
    }
    cout << 0 << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
    // cin >> Case;
    while(Case--) work();
    return 0;
}