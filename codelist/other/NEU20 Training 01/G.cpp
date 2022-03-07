#include <bits/stdc++.h>

#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)

using namespace std;
const int N = 209;
int s[N], t, vis[N], sc;
int n, m, low[N], dfn[N], dfncnt;
vector<int> ver[N];
void tarjan(int x) {
    low[x] = dfn[x] = ++dfncnt;
    s[++t] = x; vis[x] = 1;
    for(auto y : ver[x]) {
        if(!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if(vis[y]){
            low[x] = min(low[x], dfn[y]);
        }
    }
    if(dfn[x] == low[x]) {
        int z = -1;
        ++sc;
        while(z != x) {
            vis[s[t]] = 0;
            z = s[t];
            t--;
        }
    }
}
void work() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) ver[i].clear();
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        x++; y++;
        ver[x].push_back(y);
    }
    sc = 0;
    dfncnt = 0;
    memset(low, 0, sizeof(int) * (n + 3));
    memset(dfn, 0, sizeof(int) * (n + 3));
    for(int i = 1; i <= n; i++) {
        if(!dfn[i]) {
            tarjan(i);
        }
    }
    cout << sc << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case;
    cin >> Case;
    while (Case--) work();
    return 0;
}
