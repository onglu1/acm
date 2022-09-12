//
// Created by onglu on 2022/4/24.
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
const int mod = 1e9 + 7;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, k;
int f[50009][27][27];
vector<int> ver[N];
void dfs(int x, int pre) {
    f[x][1][0] = 1;
    for(auto y : ver[x]) if(y != pre)
        dfs(y, x);
    for(auto y : ver[x]) if(y != pre) {
            int g[27][27] = {0};
            for(int i = 1; i <= m; i++) {
                for(int j = 1; j <= m; j++) {
                    for(int p = 0; p <= 2 * k; p++) {
                        for(int q = 0; q <= 2 * k; q++) {
                            if(p + q + 1 <= 2 * k)
                                g[i + j][max(p, q + 1)] = (g[i + j][max(p, q + 1)] + f[x][i][p] * f[y][j][q] % mod) % mod;
                            g[i][p] = (g[i][p] + f[x][i][p] * f[y][j][q] % mod) % mod;
                        }
                    }
                }
            }
            memcpy(f[x], g, sizeof(g));
        }
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
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j <= k; j++)
            ans = (ans + f[1][i][j]) % mod;
    }
    cout << f[2][1][0] << endl;
    cout << f[3][2][1] << endl;

    cout << ans << endl;
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