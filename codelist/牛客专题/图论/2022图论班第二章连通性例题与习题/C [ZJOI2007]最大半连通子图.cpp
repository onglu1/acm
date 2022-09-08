//
// Created by onglu on 2022/5/31.
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
pair<int, vector<int> > kosaraju(vector<vector<int> > ver) {
    int n = ver.size() - 1;
    vector<int> scc(n + 1);
    int cnt = 0;
    vector<vector<int> > rver(n + 1);
    for(int i = 1; i <= n; i++) {
        for(auto y : ver[i]) {
            rver[y].push_back(i);
        }
    }
    vector<int> vis(n + 1);
    stack<int> q;
    auto dfs1 = [&](auto &&me, int x) -> void {
        vis[x] = 1;
        for(auto y : ver[x]) if(!vis[y]) {
                me(me, y);
            }
        q.push(x);
    };
    auto dfs2 = [&](auto &&me, int x) -> void {
        vis[x] = 0;
        scc[x] = cnt;
        for(auto y : rver[x]) if(vis[y]) {
                me(me, y);
            }
    };
    for(int i = 1; i <= n; i++) if(!vis[i]) dfs1(dfs1, i);
    while(q.size()) {
        int x = q.top();
        q.pop();
        if(vis[x]) {
            cnt++;
            dfs2(dfs2, x);
        }
    }
    return {cnt, scc};
}
vector<vector<int> > reduction(vector<vector<int> > ver, vector<int> scc, int scnt) {
    int n = ver.size() - 1;
    vector<vector<int> > sver(scnt + 1);
    map<pair<int, int>, int> M;
    for(auto x = 1; x <= n; x++) {
        for(auto y : ver[x]) {
            if(scc[x] != scc[y] && !M.count({scc[x], scc[y]})) {
                M[{scc[x], scc[y]}] = 1;
                sver[scc[x]].push_back(scc[y]);
            }
        }
    }
    return sver;
}
int n, m, a[N], mod;
vector<vector<int> > ver;
void work() {
    cin >> n >> m >> mod;
    ver = vector<vector<int>> (n + 1);
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        ver[x].push_back(y);
    }
    auto t = kosaraju(ver);
    auto scnt = t.first;
    auto scc = t.second;
    auto sver = reduction(ver, scc, scnt);
    vector<int> siz(scnt + 1);
    for(int i = 1; i <= n; i++) {
        siz[scc[i]] += 1;
    }
    vector<int> f(scnt + 1), g(scnt + 1), in(scnt + 1);
    for(auto x = 1; x <= scnt; x++) {
        for(auto y : sver[x]) {
            in[y] += 1;
        }
    }
    auto dfs = [&] (auto &&me, int x) -> void {
        if(f[x] != 0) return ;
        f[x] = siz[x];
        g[x] = 1;
        for(auto y : sver[x]) {
            me(me, y);
            int t = f[y];
            int tt = g[y];
            if(siz[x] + t > f[x]) {
                f[x] = siz[x] + t;
                g[x] = tt;
            } else if(siz[x] + t == f[x]) {
                g[x] = (g[x] + tt) % mod;
            }
        }
    };
    for(int i = 1; i <= scnt; i++) dfs(dfs, i);
    // for(int i = 1; i <= n; i++) cout << scc[i] << " "; cout << endl;
    // for(int i = 1; i <= scnt; i++) cout << f[i] << " "; cout << endl;
    // for(int i = 1; i <= scnt; i++) cout << g[i] << " "; cout << endl;
    int maxn = 0;
    for(int i = 1; i <= scnt; i++) {
        maxn = max(maxn, f[i]);
    }
    int ans = 0;
    for(int i = 1; i <= scnt; i++) {
        if(in[i] == 0 && f[i] == maxn) {
            ans = (ans + g[i]) % mod;
        }
    }
    cout << maxn << endl << ans << endl;
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