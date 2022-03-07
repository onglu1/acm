#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 1009;
int n, m, k, vis[N];
int cut[N], dfn[N], low[N], dfntot, dc;
int head[N], nxt[N], ver[N], tot = 1;
vector<int> dcc[N];
void add(int x, int y) {
    nxt[++tot] = head[x]; head[x] = tot; ver[tot] = y;
}
namespace v_dcc {
    int s[N], t, root;
    int es[N], et;
    void tarjan(int x) {
        dfn[x] = low[x] = ++dfntot;
        s[++t] = x;
        if(x == root && head[x] == 0) {
            dcc[++dc].clear();
            dcc[dc].push_back(x);
            return ;
        }
        int flag = 0;
        for(int i = head[x]; i; i = nxt[i]) {
            int y = ver[i];
            if(!dfn[y]) {
                tarjan(y);
                low[x] = min(low[x], low[y]);
                if(low[y] >= dfn[x]) {
                    flag++;
                    if(x != root || flag > 1) cut[x] = true;
                    dcc[++dc].clear();
                    int z = -1;
                    while(z != y) {
                        z = s[t--];
                        dcc[dc].push_back(z);
                    }
                    dcc[dc].push_back(x);
                }
            } else low[x] = min(low[x], dfn[y]);
        }
    }
    void get_cut() {
        for(int i = 1; i <= n; i++)
            if(!dfn[i])
                tarjan(root = i);
    }
}
int fac[N], inv[N];
int Pow(int a, int p) {
    int ans = 1;
    for( ; p; p >>= 1, a = a * a % mod)
        if(p & 1)
            ans = ans * a % mod;
    return ans % mod;
}
void init() {
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    for(int i = 2; i < N; i++) fac[i] = fac[i - 1] * i % mod;
    for(int i = 2; i < N; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    for(int i = 2; i < N; i++) inv[i] = inv[i - 1] * inv[i] % mod;
}
int C(int n, int m) {
    if(m < 0 || m > n) return 0;
    return fac[n] * inv[n - m] % mod * inv[m] % mod;
}
signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    int ans = 1;
    v_dcc::get_cut();
    for(int t = 1; t <= dc; t++) {
        memset(vis, 0, sizeof(int) * (n + 10));
        for(auto x : dcc[t]) vis[x] = 1;
        int mtot = 0;
        for(auto x : dcc[t]) {
            for(int i = head[x]; i; i = nxt[i]) {
                if(vis[ver[i]]) {
                    mtot++;
                }
            }
        }
        mtot /= 2;
        if(mtot == dcc[t].size()) {
            int tmp = 0;
            for(int i = 1; i <= dcc[t].size(); i++) {
                tmp = (tmp + Pow(k, __gcd((int)dcc[t].size(), i))) % mod;
            }
            tmp = tmp * Pow(dcc[t].size(), mod - 2) % mod;
            ans = (ans * tmp) % mod;
        } else if(mtot > dcc[t].size()) {
            ans = (ans * C(mtot + k - 1, k - 1)) % mod;
        } else {
            ans = (ans * Pow(k, mtot)) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}