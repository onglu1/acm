#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e5 + 1009;
struct Edge {
    int p, l, y, h;
};
int n, m, k, cost[N];
vector<Edge> ver[N];
vector<int> tmp[N], ans[N];
void work() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        ver[i].clear();
        tmp[i].clear();
        ans[i].clear();
    }
    for(int i = 1; i <= n; i++) cin >> cost[i];
    for(int i = 1; i <= k; i++) {
        int a, b, c, d, h;
        cin >> a >> b >> c >> d >> h;
        ver[a].push_back({b, c, d, h});
        tmp[a].push_back(b);
        tmp[c].push_back(d);
    }
    tmp[1].push_back(1);
    tmp[n].push_back(m);
    for(int i = 1; i <= n; i++) {
        sort(ver[i].begin(), ver[i].end(), [](const Edge &a, const Edge &b){
            return a.p < b.p;
        });
        sort(tmp[i].begin(), tmp[i].end());
        tmp[i].resize(unique(tmp[i].begin(), tmp[i].end()) - tmp[i].begin());
    }
    for(int i = 1; i <= n; i++) {
        ans[i].resize(tmp[i].size(), (1ll << 61) - 1);
    }
    ans[1][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j + 1 < ans[i].size(); j++) if(ans[i][j] < ((1ll << 61) - 1)){
            ans[i][j + 1] = min(ans[i][j + 1], ans[i][j] + (tmp[i][j + 1] - tmp[i][j]) * cost[i]);
        }
        for(int j = (int)ans[i].size() - 1; j - 1 >= 0; j--) if(ans[i][j] < ((1ll << 61) - 1)) {
            ans[i][j - 1] = min(ans[i][j - 1], ans[i][j] + (tmp[i][j] - tmp[i][j - 1]) * cost[i]);
        }
        for(auto tt : ver[i]){
            int l = tt.l, y = lower_bound(tmp[l].begin(), tmp[l].end(), tt.y) - tmp[l].begin();
            int p = lower_bound(tmp[i].begin(), tmp[i].end(), tt.p) - tmp[i].begin();
            int h = tt.h;
            if(ans[i][p] < ((1ll << 61) - 1))
                ans[l][y] = min(ans[l][y], ans[i][p] - h);
        }
    }
    int p = lower_bound(tmp[n].begin(), tmp[n].end(), m) - tmp[n].begin();
    if(ans[n][p] >= (1ll << 61) - 1) cout << "NO ESCAPE\n";
    else cout << ans[n][p] << "\n";
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