//
// Created by onglu on 2022/6/24.
//

#include <bits/stdc++.h>

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
//const int N = 309;
int n, m, a[N], tree[N];
map<int, int> pos;
struct node {
    int id, l, r;
};
vector<node> v;
void add(int x, int y) {
    for ( ; x <= n; x += x & -x)
        tree[x] += y;
}
int query(int x) {
    int ans = 0;
    for ( ; x; x -= x & -x)
        ans += tree[x];
    return ans;
}
int ans[N];
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        v.push_back({i, l, r});
    }
    std::sort(v.begin(), v.end(), [](const node &a, const node &b) {
        return a.r < b.r;
    });
    int now = 0;
    for (auto x: v) {
        while(now < x.r) {
            now += 1;
            if(pos.count(a[now])) {
                add(pos[a[now]], -1);
            }
            add(now, 1);
            pos[a[now]] = now;
        }
        ans[x.id] = query(x.r) - query(x.l - 1);
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
    // cin >> Case;
    while(Case--) work();
    return 0;
}