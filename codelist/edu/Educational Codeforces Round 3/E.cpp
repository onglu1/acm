//
// Created by onglu on 2022/4/27.
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
const int N = 2e5 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
struct node {
    int x, y, w, id;
} a[N];
int n, m, pre[N];
vector<node> ver[N];
int fid(int x) {
    return pre[x] == x ? x : (pre[x] = fid(pre[x]));
}
int siz[N], son[N], lfa[N], top[N], dth[N], fa[N], id[N], rid[N];
void dfs1(int x, int pre) {
    siz[x] = 1;
    son[x] = 0;
    dth[x] = dth[pre] + 1;
    fa[x] = pre;
    for(auto e : ver[x]) if(e.y != pre) {
        dfs1(e.y, x);
        lfa[e.y] = e.w;
        siz[x] += siz[e.y];
        if(siz[e.y] > siz[son[x]]) son[x] = e.y;
    }
}
void dfs2(int x, int ltp) {
    top[x] = ltp;
    static int cnt = 0;
    id[x] = ++cnt;
    rid[cnt] = x;
    if(son[x]) {
        dfs2(son[x], ltp);
    }
    for(auto e : ver[x]) if(e.y != fa[x] && e.y != son[x]) {
        dfs2(e.y, e.y);
    }
}
int tree[N * 4];
void build(int l, int r, int rt) {
    if(l == r) {
        tree[rt] = lfa[rid[l]];
        return ;
    }
    build(l, Mid, lson); build(Mid + 1, r, rson);
    tree[rt] = max(tree[lson], tree[rson]);
}
int query(int l, int r, int L, int R, int rt) {
    if(L > R) return 0;
    if(L <= l && r <= R) return tree[rt];
    int ans = 0;
    if(L <= Mid) ans = max(ans, query(l, Mid, L, R, lson));
    if(Mid <  R) ans = max(ans, query(Mid + 1, r, L, R, rson));
    return ans;
}
int maxLength(int x, int y) {
//    int debg = 0;
//    if(x == 4 && y == 5) debg = 1;
    int ans = 0;
    while(top[x] != top[y]) {
//        cout << x << " " << y << " " << top[x] << " " << top[y] << " " << dth[top[x]] << " " << dth[top[y]] << ans << endl;
        if(dth[top[x]] > dth[top[y]]) {
            ans = max(ans, query(1, n, id[top[x]], id[x], 1));
            x = fa[top[x]];
        } else {
            ans = max(ans, query(1, n, id[top[y]] + 1, id[y], 1));
            ans = max(ans, lfa[top[y]]);
            y = fa[top[y]];
        }
    }
    if(dth[x] < dth[y]) swap(x, y);
//    if(debg == 1) {
//        cout << "debg = " << ans << " " << x << " " << y << " " << id[x] << " " << id[y] << endl;
//        cout << id[2] << " " << lfa[5] << " " << lfa[2] << endl;
//
//        for(int i = 1; i <= n; i++) {
//            cout << id[i] << " " << query(1, n, i, i, 1) << endl;
//        }
//        cout << rid[2] << endl;
//    }
    return max(ans, query(1, n, id[y] + 1, id[x], 1));
}
int vis[N], ans[N];
void work() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> a[i].x >> a[i].y >> a[i].w;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + m, [](const node &a, const node &b) {
        return a.w < b.w;
    });
    int sum = 0;
    for(int i = 1; i <= n; i++) pre[i] = i;
    for(int i = 1; i <= m; i++) {
        if(fid(a[i].x) != fid(a[i].y)) {
            sum += a[i].w;
            vis[i] = 1;
            pre[fid(a[i].x)] = fid(a[i].y);
            ver[a[i].x].push_back(a[i]);
            ver[a[i].y].push_back({a[i].y, a[i].x, a[i].w});
        }
    }
    dfs1(1, 0); dfs2(1, 1);
    build(1, n, 1);
//    cout << maxLength(5, 4) << endl;
//    for(int i = 1; i <= n; i++) {
//        for(auto e : ver[i]) {
//            if(e.x < e.y)
//                cout << e.x << " " << e.y << " " << e.w << endl;
//        }
//    }
    for(int i = 1; i <= m; i++) {
        if(vis[i]) {
            ans[a[i].id] = sum;
            continue;
        }
        ans[a[i].id] = sum - maxLength(a[i].x, a[i].y) + a[i].w;
    }
    for(int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
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
//    cin >> Case;
    while (Case--) work();
    return 0;
}