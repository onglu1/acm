#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e6 + 1009;
int n, m, tree[N];
struct node {
    int l, r;
} a[N];
void add(int x, int y) {
    for( ; x < N; x += x & -x)
        tree[x] += y;
}
int query(int x) {
    int ans = 0;
    for( ; x ; x -= x & -x)
        ans += tree[x];
    return ans;
}
signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
        freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
        freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int l, r;
        cin >> a[i].l >> a[i].r;
    }
    sort(a + 1, a + 1 + n, [](const node &a, const node &b) {
        return a.r - a.l < b.r - b.l;
    });
    int now = 1;
    for(int i = 1; i <= m; i++) {
        while(now <= n && a[now].r - a[now].l + 1 < i) {
            add(a[now].l, 1);
            add(a[now].r + 1, -1);
            now++;
        }
        int ans = n - now + 1;
        for(int j = 0; j <= m; j += i) {
            ans += query(j);
        }
        cout << ans << endl;
    }
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}
/*
 * 包含xy的区间个数 = (r >= y) - (l > x && r >= y)
 *
 */