//
// Created by onglu on 2022/3/16.
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
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N], t[N];
int tree[N], lzt[N];
vector<pair<int, int> > v;
void update(int rt) {
    tree[rt] = min(tree[lson], tree[rson]);
}
void pushdown(int l, int r, int rt) {
    if(lzt[rt] == 0) return ;
    tree[lson] -= lzt[rt]; lzt[lson] += lzt[rt];
    tree[rson] -= lzt[rt]; lzt[rson] += lzt[rt];
    lzt[rt] = 0;
}
void modify(int l, int r, int L, int R, int x, int rt) {
    if(L <= l && r <= R) {
        tree[rt] -= x;
        lzt[rt] += x;
        return ;
    }
    pushdown(l, r, rt);
    if(L <= Mid) modify(l, Mid, L, R, x, lson);
    if(Mid <  R) modify(Mid + 1, r, L, R, x, rson);
    update(rt);
}
int query(int l, int r, int L, int R, int rt) {
    if(L <= l && r <= R) return tree[rt];
    pushdown(l, r, rt);
    int minn = 1ll << 61;
    if(L <= Mid) minn = min(minn, query(l, Mid, L, R, lson));
    if(Mid <  R) minn = min(minn, query(Mid + 1, r, L, R, rson));
    return minn;
}
void build(int l, int r, int rt) {
    if(l == r) {
        tree[rt] = t[l];
        return ;
    }
    build(l, Mid, lson); build(Mid + 1, r , rson);
    update(rt);
}
void work() {
    cin >> n >> m;
    for(int i = 1; i < n; i++) {
        cin >> t[i];
    }
    build(1, n - 1, 1);
    for(int j = 1; j <= m; j++) {
        int x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        v.emplace_back(y, x);
    }
    int ans = 0;
    sort(all(v));
    for(auto x : v) {
        int r = x.first + 1, l = x.second + 1;
        int minn = query(1, n - 1, l, r - 1, 1);
        ans += minn;
        modify(1, n - 1, l, r - 1, minn, 1);
    }
    cout << ans << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    work();
    return 0;
}