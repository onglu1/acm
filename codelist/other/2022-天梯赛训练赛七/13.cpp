//
// Created by onglu on 2022/3/26.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define int long long
#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, a[N], vis[N], in[N];
int f[N];
vector<int> ver[N];
void dfs(int x) {
    if(vis[x]) return ;
    vis[x] = 1;
    for(auto y : ver[x]) dfs(y);
}
void work() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        assert(1 <= x && x <= n);
        assert(1 <= y && y <= n);
        ver[x].push_back(y);
    }
    int s, t;
    cin >> s >> t;
    dfs(s);
    int ok = 1;
    for(int i = 1; i <= n; i++) if(vis[i]) {
        for(auto y : ver[i]) in[y]++;
    }
    queue<int> q;
    q.push(s);
    f[s] = 1;
    while(q.size()) {
        int x = q.front(); q.pop();
        if(x == t) continue;
        if(x != t && ver[x].size() == 0) ok = 0;
        for(auto y : ver[x]) {
            (f[y] += f[x]) %= mod;
            in[y]--;
            if(in[y] == 0) {
                q.push(y);
            }
        }
    }
    cout << f[t] << " " << ((ok) ? "Yes" : "No") << endl;

}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
//    cin >> Case;
    while (Case--) work();
    return 0;
}