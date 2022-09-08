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
int n, m, a[N];
vector<vector<int> > ver;
void work() {
    cin >> n >> m;
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
    int id = 0;
    for(auto x = 1; x <= scnt; x++) {
        if(sver[x].size() == 0) {
            if(id == 0) id = x;
            else id = -1;
        }
    }
    if(id == 0 || id == -1) {
        cout << 0 << endl;
        return ;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(scc[i] == id) {
            ans += 1;
        }
    }
    cout << ans << endl;
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