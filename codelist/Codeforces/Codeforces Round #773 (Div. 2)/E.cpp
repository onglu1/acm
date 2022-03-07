//
// Created by onglu on 2022/2/27.
//

#include <bits/stdc++.h>

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
int n, m, tree[N];
int pre[N], siz[N], a[N];
int fid(int x) {
    return pre[x] == x ? x : (pre[x] = fid(pre[x]));
}
int mg(int x, int y) {
    if(x == 0 || y == 0) return x + y;
    else return min(x, y);
}
void update(int rt) {
    tree[rt] = mg(tree[lson], tree[rson]);
}
void modify(int l, int r, int x, int v, int rt) {
    if(l == r) {
        if(tree[rt] == 0) tree[rt] = v;
        else tree[rt] = min(tree[rt], v);
        return ;
    }
    if(x <= Mid) modify(l, Mid, x, v, lson);
    else modify(Mid + 1, r, x, v, rson);
    update(rt);
}
int query(int l, int r, int L, int R, int rt) {
    if(l > R || r < L) return 0;
    if(L <= l && r <= R) return tree[rt];
    int p = 0;
    p = mg(p, query(l, Mid, L, R, lson));
    p = mg(p, query(Mid + 1, r, L, R, rson));
    return p;
}
void change(int l, int r, int x) {
    if(x == 0) {
        int p = fid(r);
        while(p >= l) {
            pre[p] = fid(p - 1);
            siz[fid(p - 1)] += siz[p];
            a[p] = 0;
            p = fid(p);
        }
    } else {
//        cout << l << endl;
        modify(1, n, l, r, 1);
    }

}
string ask(int x) {
    if(a[x] == 0) return "NO";
    int l = x;
    if(x != 1) l = fid(x - 1) + 1;
    int r = x + siz[x];
    int t = query(1, n, l, x, 1);
//    cout << l << " " << r << " " << x << " " << query(1, n, l, x, 1) << endl;
    if(t != 0 && t < r) return "YES";
    else return "N/A";

}
void work() {
    cin >> n >> m;
    for(int i = 0; i <= n; i++) {
        a[i] = 1;
        pre[i] = i;
        siz[i] = 1;
    }
    for(int i = 1; i <= m; i++) {
        int opt, l, r, x;
        cin >> opt;
        if(opt == 0) {
            cin >> l >> r >> x;
            change(l, r, x);
        } else {
            cin >> x;
            cout << ask(x) << endl;
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
    while (Case--) work();
    return 0;
}