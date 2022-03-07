#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 1009;
int n, cnt[29], f[29][5009];
char c[5009];
int inv[N], fac[N];
void init() {
    inv[0] = inv[1] = fac[0] = fac[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    for(int i = 2; i < N; i++) inv[i] = inv[i] * inv[i - 1] % mod;
    for(int i = 2; i < N; i++) fac[i] = fac[i - 1] * i % mod;
}
int C(int n, int m) {
//    if(m > n || m < 0) return 0;
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
    cin >> c; n = strlen(c);
    for(int i = 0; i < n; i++) {
        cnt[c[i] - 'a' + 1]++;
    }
    int sum = 0;
    f[0][0] = 1;
    for(int i = 1; i <= 26; i++) {
        for(int j = 0; j <= sum; j++) {
            for(int k = 0; k <= cnt[i]; k++) {
                f[i][j + k] = (f[i][j + k] + f[i - 1][j] * C(j + k, k) % mod) % mod;
            }
        }
        sum += cnt[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = (ans + f[26][i]) % mod;
    }
    cout << ans << endl;
    return 0;
}
/*
 * f[i][j] 表示前i个位置，组成长度为j的串的方案数，枚举当前串几个转移
 *
 */