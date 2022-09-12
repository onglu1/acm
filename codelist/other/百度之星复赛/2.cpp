//
// Created by onglu on 2022/4/24.
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
const int mod = 1e9 + 7;
const int N = 5e4 + 10;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, k, siz[N];
int f[N][30][30];
int t[N], g[30][30];
vector<int> ver[N];

void dfs(int x, int pre) {
    f[x][1][1] = 1;
    siz[x] = 1;
    for(auto y: ver[x])
        if(y != pre) {
            dfs(y, x);
            memset(g, 0, sizeof(g));
            for(int i = 1; i <= m && i <= siz[x]; i++) {
                for(int p = 1; p <= 2 * k + 1 && p <= siz[x]; p++) if(f[x][i][p] != 0) {
                    for(int j = 1; j + i <= m && j <= siz[y]; j++) {
                        for(int q = 1; q + p <= 2 * k + 1 && q <= siz[y]; q++) {
                            g[i + j][max(p, q + 1)] = (g[i + j][max(p, q + 1)] + 1ll * f[x][i][p] * f[y][j][q] % mod) % mod;
                        }
                    }
                    g[i][p] = (g[i][p] + 1ll * f[x][i][p] * t[y] % mod) % mod;
                }
            }
            for(int i = 0; i <= m; i++) {
                for(int j = 0; j <= 2 * k + 1; j++) {
                    f[x][i][j] = g[i][j];
                }
            }
            siz[x] += siz[y];
        }
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= 2 * k + 1; j++)
            t[x] = (t[x] + f[x][i][j]) % mod;
}

void work() {
    cin >> n >> m >> k;
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    dfs(1, 1);
    cout << t[1] << endl;
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
    while(Case--) work();
    return 0;
}