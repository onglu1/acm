#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 3e5 + 1009;
int n, w, h, ans;
pair<int, int> p[N], a[N * 4], b[N * 4];
int tree[N * 4], lzt[N * 4];
void pushdown(int l, int r, int rt) {
    if(lzt[rt] == 0) return ;
    lzt[lson] += lzt[rt]; lzt[rson] += lzt[rt];
    tree[lson] += lzt[rt]; tree[rson] += lzt[rt];
    lzt[rt] = 0;
}
void update(int rt) {
    tree[rt] = max(tree[lson], tree[rson]);
}
void modify(int l, int r, int L, int R, int v, int rt) {
    if(r < L || l > r) return ;
    if(L <= l && r <= R) {
        tree[rt] += v;
        lzt[rt] += v;
        return ;
    }
    pushdown(l, r, rt);
    if(L <= Mid) modify(l, Mid, L, R, v, lson);
    if(Mid <  R) modify(Mid + 1, r, L, R, v, rson);
    update(rt);
}
void work() {
    memset(tree, 0, sizeof(tree));
    memset(lzt, 0, sizeof(lzt));
    int l = 0, r = 0;
    sort(p + 1, p + 1 + n);
    for(int i = 1; i < n; i++) {
        if(p[i].y >= h / 2) {
            int nxt = i - 1;
            while(l && a[l].y > p[i].y) {
                modify(1, n, a[l].x, nxt, p[i].y - a[l].y, 1);
                nxt = a[l].x - 1;
                l--;
            }
            if(nxt != i - 1) a[++l] = {nxt + 1, p[i].y};
        } else {
            int nxt = i - 1;
            while(r && b[r].y < p[i].y) {
                modify(1, n, b[r].x, nxt, b[r].y - p[i].y, 1);
                nxt = b[r].x - 1;
                r--;
            }
            if(nxt != i - 1) b[++r] = {nxt + 1, p[i].y};
        }
        a[++l] = {i, h}; b[++r] = {i, 0};
        modify(1, n, i, i, h - p[i].x, 1);
        ans = max(ans, p[i + 1].x + tree[1]);
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> w >> h >> n;
    for(int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
    p[++n] = {0, 0}; p[++n] = {w, h};
    work();
    for(int i = 1; i <= n; i++) swap(p[i].x, p[i].y);
    swap(w, h);
    work();
    cout << ans * 2 << endl;
    return 0;
}