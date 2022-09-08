//
// Created by onglu on 2022/3/22.
//

#include <bits/stdc++.h>

#define aint(a) a.begin(),a.end()
#define raint(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
#define int long long
using namespace std;
const int N = 250 + 9, mod = 998244353;
int n, k, a[N], f[N][N][N], g[N][N];
int fac[N];
int Pow(int a, int p) {
    int ans = 1;
    for( ; p; p >>= 1, a = a * a % mod)
        if(p & 1)
            ans = ans * a % mod;
    return ans % mod;
}

void work() {
    cin >> n >> k;
    for(int i = 1; i <= k; i++) {
        f[1][i][1] = g[1][i] = 1;
    }
    for(int i = 2; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            int sum = 0;
            for (int p = 1; p < j; p++) {
                sum += (int) g[i - 1][p] * Pow(k + 1 - j, i - 1) % mod;
                if (sum >= mod) sum -= mod;
            }
            f[i][j][1] = sum;
            for (int p = 2; p <= i; p++)
                f[i][j][p] = (int) f[i - 1][j][p - 1] * Pow(k + 1 - j, i - 1) % mod * Pow(p, mod - 2) % mod;
            sum = 0;
            for (int p = 1; p <= i; p++) {
                sum += f[i][j][p];
                if(sum >= mod) sum -= mod;
            }
            g[i][j] = sum;
        }
    }
    int ans = 0;
    fac[0] = 1;
    for(int i = 1; i < n; i++) fac[i] = fac[i - 1] * i % mod;
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            ans = ans + (int)fac[n - 1] * f[n - 1][i][j] % mod;
            if(ans >= mod) ans -= mod;
        }
    }
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
    while (Case--) work();
    return 0;
}