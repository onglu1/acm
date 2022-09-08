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
int n, m, a[N], dfn[N], low[N];
int dfntot, findt = 0, s, t, ans = 0x3f3f3f3f;
vector<vector<int> > ver;
void dfs(int x, int pre) {
    if(x == t) findt = 1;
    dfn[x] = low[x] = ++dfntot;
    for(auto y : ver[x]) if(y != pre) {
        int tmp = findt;
        if(!dfn[y]) {
            dfs(y, x);
            low[x] = min(low[x], low[y]);
        } else {
            low[x] = min(low[x], dfn[y]);
        }
        if(tmp == 0 && findt == 1 && low[y] >= dfn[x] && x != s && x != t) {
            ans = min(ans, x);
        }
    }
}
void work() {
    cin >> n;
    ver = vector<vector<int>> (n + 1);
    while(1) {
        int x, y;
        cin >> x >> y;
        if(x == 0 && y == 0) break;
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    cin >> s >> t;
    dfs(s, s);
    if(ans == 0x3f3f3f3f) cout << "No solution" << endl;
    else cout << ans << endl;
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