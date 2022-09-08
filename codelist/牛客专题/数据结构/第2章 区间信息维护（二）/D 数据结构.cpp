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
int sum[N], sqsum[N], lzt[N], lzt2[N];
void update(int rt) {
    sum[rt] = sum[lson] + sum[rson];
    sqsum[rt] = sqsum[lson] + sqsum[rson];
}
void build(int l, int r, int rt) {
    lzt[rt] = 0;
    lzt2[rt] = 1;
    if(l == r) {
        sum[rt] = a[l];
        sqsum[rt] = a[l] * a[l];
        return;
    }
    build(l, Mid, lson);
    build(Mid + 1, r, rson);
    update(rt);
}
void pushdown(int l, int r, int rt) {
    if(lzt[rt] == 0 && lzt2[rt] == 1) return ;
    lzt[lson] *= lzt2[rt]; lzt[rson] *= lzt2[rt];
    lzt2[lson] *= lzt2[rt]; lzt2[rson] *= lzt2[rt];
    sum[lson] *= lzt2[rt]; sum[rson] *= lzt2[rt];
    sqsum[lson] *= lzt2[rt] * lzt2[rt]; sqsum[rson] *= lzt2[rt] * lzt2[rt];
    lzt2[rt] = 1;
    lzt[lson] += lzt[rt]; lzt[rson] += lzt[rt];
    sqsum[lson] += (Mid - l + 1) * lzt[rt] * lzt[rt] + 2 * lzt[rt] * sum[lson];
    sqsum[rson] += (r - Mid) * lzt[rt] * lzt[rt] + 2 * lzt[rt] * sum[rson];
    sum[lson] += (Mid - l + 1) * lzt[rt];
    sum[rson] += (r - Mid) * lzt[rt];
    lzt[rt] = 0;
}
void modify(int l, int r, int L, int R, int rt, int x) {
    if(L <= l && r <= R) {
        sqsum[rt] += (r - l + 1) * x * x + 2 * x * sum[rt];
        sum[rt] += (r - l + 1) * x;
        lzt[rt] += x;
        return ;
    }
    pushdown(l, r, rt);
    if(L <= Mid) modify(l, Mid, L, R, lson, x);
    if(Mid <  R) modify(Mid + 1, r, L, R, rson, x);
    update(rt);
}

void mul(int l, int r, int L, int R, int rt, int x) {
    if(L <= l && r <= R) {
        sqsum[rt] *= x * x;
        sum[rt] *= x;
        lzt[rt] *= x;
        lzt2[rt] *= x;
        return ;
    }
    pushdown(l, r, rt);
    if(L <= Mid) mul(l, Mid, L, R, lson, x);
    if(Mid <  R) mul(Mid + 1, r, L, R, rson, x);
    update(rt);
}
pair<int, int> query(int l, int r, int L, int R, int rt) {
    if(L <= l && r <= R) return {sum[rt], sqsum[rt]};
    pushdown(l, r, rt);
    if(R <= Mid) return query(l, Mid, L, R, lson);
    else if(Mid < L) return query(Mid + 1, r, L, R, rson);
    else {
        auto x1 = query(l, Mid, L, R, lson);
        auto x2 = query(Mid + 1, r, L, R, rson);
        return {x1.first + x2.first, x1.second + x2.second};
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
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 1);
    while(m--) {
        int opt;
        cin >> opt;
        if(opt == 1) {
            int l, r;
            cin >> l >> r;
            cout << query(l, r).first << endl;
        } else if(opt == 2) {
            int l, r;
            cin >> l >> r;
            cout << query(l, r).second << endl;
        } else if(opt == 3) {
            int l, r, x;
            cin >> l >> r >> x;
            mul(l, r, x);
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            modify(l, r, x);
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
    // cin >> Case;
    while(Case--) work();
    return 0;
}