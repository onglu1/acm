#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e5 + 1009;
int n, in[N], ans[N];
vector<int> ver[N], id[N];
void dfs(int x, int pre, int t) {
    for(int i = 0; i < ver[x].size(); i++) {
        if(ver[x][i] == pre) continue;
        ans[id[x][i]] = 2 + t;
        dfs(ver[x][i], x, t ^ 1);
    }
}
void work() {
    memset(in, 0, sizeof(int) * (n + 10));
    cin >> n;
    for(int i = 1; i <= n; i++) ver[i].clear(), id[i].clear();
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        in[x]++; in[y]++;
        ver[x].push_back(y);
        id[x].push_back(i);
        ver[y].push_back(x);
        id[y].push_back(i);
    }
    for(int i = 1; i <= n; i++) if(in[i] > 2) {
        cout << -1 << "\n";
        return ;
    }
    for(int i = 1; i < n; i++) {
        if(in[i] == 1) {
            dfs(i, 0, 0);
        }
    }
    for(int i = 1; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case = 0;
    cin >> Case;
    while (Case--) work();

    return 0;
}