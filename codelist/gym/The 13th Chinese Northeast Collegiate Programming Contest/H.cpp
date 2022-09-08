#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e5 + 1009;
int n, m, a[N];
int sum[N * 4], tree[N * 4];
void update(int rt) {
    tree[rt] = tree[lson] + tree[rson];
    sum[rt] = sum[lson] + sum[rson];
}
void build(int l, int r, int rt) {
    if(l == r) {
        sum[rt] = a[l];
        if(a[l] >= 0) tree[rt] = a[l];
        else tree[rt] = 0;
        return ;
    }
    build(l, Mid, lson); build(Mid + 1, r, rson);
    update(rt);
}
void modify(int l, int r, int rt, int x, int k) {
    if(l == r) {
        sum[rt] = k;
        if(k >= 0) tree[rt] = k;
        else tree[rt] = 0;
        return ;
    }
    if(x <= Mid) modify(l, Mid, lson, x, k);
    else modify(Mid + 1, r, rson, x, k);
    update(rt);
}
int query(int l, int r, int rt, int L, int R, int isSum) {
//    if(!isSum) cerr << l << " " << r << endl;
    if(L <= l && r <= R) return isSum ? sum[rt] : tree[rt];
    int ans = 0;
    if(L <= Mid) ans += query(l, Mid, lson, L, R, isSum);
    if(Mid <  R) ans += query(Mid + 1, r, rson, L, R, isSum);
    return ans;
}
void work() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = n; i >= 1; i--) a[i] -= a[i - 1];
    build(1, n, 1);
    for(int i = 1; i <= m; i++) {
        int opt, l, r, k;
        cin >> opt >> l >> r;
//        cout << i << endl;
        if(opt == 1) {
            cin >> k;
            a[l] += k;
            a[r + 1] -= k;
            modify(1, n, 1, l, a[l]);
            if(r + 1 <= n) modify(1, n, 1, r + 1, a[r + 1]);
        } else {
            int ans = query(1, n, 1, 1, l, 1);
//            cout << i << endl;
            if(ans < 0) ans = 0;
            if(l < r) {
                ans += query(1, n, 1, l + 1, r, 0);
            }
//            cout << i << endl;
            cout << ans << endl;
        }
    }
}
signed main()
{
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios ::sync_with_stdio(0);
    cin.tie(0);
    int Case;
    cin >> Case;
    while(Case--) work();
    return 0;
}