//
// Created by onglu on 2022/5/23.
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
map<int, int> vis;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, a[N], ans;
int len(int x) {
    int t = 0;
    while(x) {
        x /= 10;
        t += 1;
    }
    return t;
}
void dfs(int n, int x, int step) {
    if(vis.count(x) && vis[x] <= step) return ;
    vis[x] = step;
    // cout << x << endl;
    int l = len(x);
    if(l > n) return ;
    if(ans != -1 && n - l + step > ans) return ;
    if(l == n) {
        if(ans == -1) ans = step;
        ans = min(ans, step);
        return ;
    }
    vector<int> t;
    int tx = x;
    while(tx > 0) {
        t.push_back(tx % 10);
        tx /= 10;
    }
    std::sort(t.begin(), t.end());
    t.resize(std::unique(t.begin(), t.end()) - t.begin());
    std::reverse(t.begin(), t.end());
    for(auto y : t) {
        dfs(n, x * y, step + 1);
    }
}
void work() {
    vis.clear();
    ans = -1;
    cin >> n >> m;
    dfs(n, m, 0);
    cout << ans << endl;
    // cout << dfs(n, m) << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << ((int)1e18) << endl;
    int Case = 1;
//    cin >> Case;
    while(Case--) work();
    return 0;
}