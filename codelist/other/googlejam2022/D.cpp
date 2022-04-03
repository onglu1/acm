//
// Created by onglu on 2022/4/2.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N];
int fa[N], min_link[N], f[N], g[N];
vector<int> ver[N];
/*
 * f[x]表示完成整棵树的最大收益
 * g[x]表示除去最小链不割的最大收益
 * f[x] = \sum(f[son]) + min_link[x] < a[x] ? a[x] - min_link[x] : 0;
 * g[x] = \sum(f[son]) - f[pos[min_link]] + g[pos[min_link]]
 *
 */
void dfs(int x) {
    if(ver[x].empty()) {
        f[x] = a[x];
        g[x] = 0;
        min_link[x] = a[x];
        return ;
    }
    min_link[x] = 1ll << 61;
    int t = 0, tans = 0, pos_min_link = ver[x][0];
    int sumf = 0;
    for(auto y : ver[x]) {
        dfs(y);
        if(min_link[y] < min_link[pos_min_link]) {
            pos_min_link = y;
        }
        sumf += f[y];
    }
    f[x] = sumf - f[pos_min_link] + g[pos_min_link] + max(min_link[pos_min_link], a[x]);
    g[x] = sumf - f[pos_min_link] + g[pos_min_link];
    min_link[x] = max(min_link[pos_min_link], a[x]);
}
void work() {
    cin >> n;
    n += 1;
    a[1] = 0;
    for(int i = 2; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        ver[i].clear();
    }
    for(int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        x += 1;
        fa[i] = x;
        ver[x].push_back(i);
    }
    dfs(1);
    static int cnt = 0;
    cnt++;
    cout << "Case #" << cnt << ": ";
    cout << f[1] << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 0;
    cin >> Case;
    while (Case--) work();
    return 0;
}