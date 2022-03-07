//
// Created by onglu on 2022/3/2.
//

#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 3e3;
const int mod = 100000007;
const double EPS = 1e-11;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, vis[N], target, siz[N];
double p[N], w[N];
vector<int> ver[N];
vector<vector<int> > cir;
int inv[N], fac[N], f[N];
int C(int n, int m) {
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
void init() {
    inv[0] = inv[1] = fac[0] = fac[1] = 1;
    for(int i = 2; i < N; i++) fac[i] = fac[i - 1] * i % mod;
    for(int i = 2; i < N; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    for(int i = 2; i < N; i++) inv[i] = inv[i] * inv[i - 1] % mod;
}
int dfs(int x) {
    vis[x] = 1;
    for(auto y : ver[x]) {
        if(y == target) {
            cir.emplace_back(vector<int>());
            cir[cir.size() - 1].push_back(x);
            return true;
        } else {
            int t = dfs(y);
            if(t == 1) {
                cir[cir.size() - 1].push_back(x);
                return true;
            }
        }
    }
    return false;
}

void get(int x) {
    siz[x] = 1;
    for(auto y : ver[x]) if(!vis[x]) {
        dfs(y);
        siz[x] += siz[y];
    }
    f[x] = 1;
    int used = 1;
    for(auto y : ver[x]) if(!vis[x]) {
        f[x] = f[x] * f[y] % mod * C(siz[x] - used, siz[y]) % mod;
        used += siz[y];
    }
}
void work() {
    cir.clear();
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++) ver[i].clear();
    for(int i = 1; i <= n; i++) {
        int x;
        scanf("%lf%lld%lf", &p[i], &x, &w[i]);
        ver[x + 1].push_back(i);
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            target = i;
            dfs(i);
        }
    }
    double ans = 0;
    for(auto v : cir) {
        double minn = 1e9;
        for (auto x: v) {
            vis[x] = 1;
            minn = min(minn, 1 / p[x] - 1 / w[x]);
        }
        ans += minn;
    }
    for(int i = 1; i <= n; i++) {
        ans += 1 / w[i];
    }
    printf("%.10f ", ans);
    int ff = 1, gsize = n;
    for(int i = 1; i <= n; i++) if(vis[i]) {
        get(i);
    }
    for(auto v : cir) {
        double minn = 1e9;
        int totsize = 0, tsize;
        int fv = 0;
        for (auto x: v) {
            minn = min(minn, 1 / p[x] - 1 / w[x]);
            totsize += siz[x];
        }
        for(int i = 0; i < v.size(); i++) if(fabs(minn - (1 / p[v[i]] - 1 / w[v[i]])) < EPS){
            int ft = 1;
            tsize = totsize;
            for(int j = i; j >= 0; j--) {
                ft = ft * f[v[j]] % mod * C(tsize - 1, siz[v[j]] - 1);
                tsize -= siz[v[j]];
            }
            for(int j = v.size() - 1; j > i; j--) {
                ft = ft * f[v[j]] % mod * C(tsize - 1, siz[v[j]] - 1);
                tsize -= siz[v[j]];
            }
            fv = (fv + ft) % mod;
        }
        ff = ff * fv % mod * C(gsize, totsize) % mod;
        gsize -= totsize;
    }
    printf("%lld\n", ff);

}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    init();
    while(~scanf("%lld", &n)) {
        if(n == 0) break;
        work();
    }
    return 0;
}
/*
 * 击破概率为p的时候，击破的期望时间为 1 + (1 - p) * 1 + (1 - p) ^ 2 +... = 1 / p
 * 每个点只有一个入度和若干个出度
 * 是由基环树组成的森林
 */