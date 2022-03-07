#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 1e6 + 1009;
const int mod = 1e9 + 7;
int n, m, k, inv[N], fac[N], pw[N];
void init() {
    inv[0] = inv[1] = fac[0] = fac[1] = 1;
    for(int i = 2; i < N; i++) fac[i] = fac[i - 1] * i % mod;
    for(int i = 2; i < N; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    for(int i = 2; i < N; i++) inv[i] = inv[i - 1] * inv[i] % mod;
    pw[0] = 1;
    for(int i = 1; i < N; i++) pw[i] = pw[i - 1] * 3 % mod;
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
    cin >> n >> m >> k;
    int ans = 0;
    init();
    int s = 1;
    for(int i = n; i <= n + m + k; i++) {
        ans = (ans + s * pw[n + m + k - i] % mod * C(i - 1, n - 1) % mod) % mod;
        if(0 >= i + 1 - n - k && i + 1 - n <= m) s = s * 2 % mod;
        else if(i + 1 - n - k <= 0 && i + 1 - n > m) s = ((s * 2 - C(i - n, m)) % mod + mod) % mod;
        else if(i + 1 - n - k > 0 && i + 1 - n <= m) s = ((s * 2 - C(i - n, i - n - k)) % mod + mod) % mod;
        else s = (((s * 2 - C(i - n, m)) % mod - C(i - n, i - n - k)) % mod + mod) % mod;
    }
    cout << ans << endl;
    return 0;
}