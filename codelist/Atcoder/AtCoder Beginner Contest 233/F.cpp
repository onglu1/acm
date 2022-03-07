#include <bits/stdc++.h>

#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)

using namespace std;
const int N = 2e5 + 1009;
int n, m, dth[N], seq[N], p[N];
struct node {
    int x, id;
};
//vector<node> opt;
vector<node> ver[N], vv[N];
vector<int> ans;
void dfs(int x, int pre) {
    for(auto tt : ver[x]) if(!dth[tt.x]) {
        int y = tt.x;
        dth[y] = dth[x] + 1;
        vv[y].push_back({x, tt.id});
        vv[x].push_back({y, tt.id});
        dfs(y, x);
    }
}
int solve(int x, int y, int pre) {
    if(p[x] == y) {
        return true;
    }

    for(auto tt : vv[x]) if(tt.x != pre) {
        int z = tt.x;
        int t = solve(z, y, x);
        if(t == 1) {
            swap(p[x], p[z]);
            ans.push_back(tt.id);
            return 1;
        }
    }
    return 0;
}
signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        ver[a].push_back({b, i});
        ver[b].push_back({a, i});
    }
    for(int i = 1; i <= n; i++) if(dth[i] == 0) {
        dth[i] = 1;
        dfs(i, 0);
    }
    for(int i = 1; i <= n; i++) {
        seq[i] = i;
    }
    sort(seq + 1, seq + 1 + n, [](const int a, const int b) {return dth[a] > dth[b];});
    for(int i = 1; i <= n; i++) {
        if(!solve(seq[i], seq[i], 0)) {
            cout << "-1" << endl;
            return 0;
        }
    }
    if(ans.size() > 500000) {
        cout << "-1\n";
        return 0;
    }
    cout << ans.size() << endl;
    for(auto x : ans) {
        cout << x << " " ;
    }
    cout << endl;
    return 0;


}
