//
// Created by onglu on 2022/6/1.
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
int n, m, a[N];
vector<vector<int>> ver;
vector<vector<int>> verid;
vector<int> dfn, low;
int dfntot;
void work() {
    cin >> n >> m;
    ver = vector<vector<int>> (n + 1);
    verid = vector<vector<int>> (n + 1);
    dfn = vector<int> (n + 1);
    low = vector<int> (n + 1);
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        ver[x].push_back(y);
        ver[y].push_back(x);
        verid[x].push_back(i);
        verid[y].push_back(i);
    }
    stack<int> sta;
    vector<int> ecc(n + 1);
    vector<int> bridge(m + 1);
    auto tarjan = [&](auto &&me, int x, int pre) -> void{
        dfn[x] = low[x] = ++dfntot;
        sta.push(x);
        for(int i = 0; i < ver[x].size(); i++) if(verid[x][i] != pre) {
            int y = ver[x][i];
            if(!dfn[y]) {
                me(me, y, verid[x][i]);
                low[x] = min(low[x], low[y]);
                if(low[y] > dfn[x]) {
                    bridge[verid[x][i]] = 1;
                }
            } else {
                low[x] = min(low[x], dfn[y]);
            }
        }
    };
    tarjan(tarjan, 1, -1);
    int ecnt = 0;
    auto dfs = [&](auto &&me, int x) -> void {
        ecc[x] = ecnt;
        for(int i = 0; i < ver[x].size(); i++) if(!bridge[verid[x][i]] && !ecc[ver[x][i]]) {
            me(me, ver[x][i]);
        }
    };
    for(int i = 1; i <= n; i++) if(!ecc[i]) {
        ecnt++;
        dfs(dfs, i);
    }
    if(ecnt == 1) {
        cout << 0 << endl;
        return ;
    }
    vector<int> deg(ecnt + 1);
    for(auto x = 1; x <= n; x++) {
        for(auto y : ver[x]) {
            if(ecc[x] != ecc[y]) {
                deg[ecc[x]] += 1;
                deg[ecc[y]] += 1;
            }
        }
    }
    int cnt = 0;
    for(auto x = 1; x <= ecnt; x++) {
        cnt += deg[x] / 2 == 1;
    }
    cout << (cnt + 1) / 2 << endl;
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