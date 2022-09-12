#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
const int N = 1e6 + 10;
int n, m;
int f[N], pre[N], nxt[N], fac[N], inv[N];

int Pow(int a, int p) {
    int ans = 1;
    for(; p; a = 1ll * a * a % mod, p >>= 1)
        if(a & 1)
            ans = 1ll * ans * a % mod;
    return ans;
}

void init() {
    inv[0] = inv[1] = 1;
    fac[0] = fac[1] = 1;
    for(int i = 2; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
    for(int i = 2; i < N; i++) inv[i] = (1ll * mod - mod / i) * inv[mod % i] % mod;
    for(int i = 2; i < N; i++) inv[i] = 1ll * inv[i - 1] * inv[i] % mod;
}

int interpolation(int *y, int n) {
    nxt[n] = (m - n + mod) % mod;
    for(int i = n - 1; i >= 0; i--) {
        nxt[i] = (m - i + mod) % mod;
        nxt[i] = 1ll * nxt[i] * nxt[i + 1] % mod;
    }
    pre[0] = m % mod;
    for(int i = 1; i <= n; i++) {
        pre[i] = (m - i + mod) % mod;
        pre[i] = 1ll * pre[i] * pre[i - 1] % mod;
    }
    int r = 0;
    for(int i = 0; i <= n; ++i) {
        int yi = y[i], s = 1;
        if(i) s = 1ll * s * pre[i - 1] % mod;
        if(i < n) s = 1ll * s * nxt[i + 1] % mod;

        int p1 = i - 0, p2 = n - i;
        s = 1ll * s * inv[p1] % mod;
        if(p2 & 1) s = 1ll * s * (mod - inv[p2]) % mod;
        else s = 1ll * s * inv[p2] % mod;

        s = 1ll * s * yi % mod;
        (r += s) %= mod;
    }
    return r;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    cin >> n >> m;
    if(n < m) {
        f[0] = 0;
        for(int i = 1; i <= n + 2; i++)
            f[i] = (f[i - 1] + Pow(i, n - 1) * n % mod) % mod;
        cout << interpolation(f, n + 2) << endl;
    } else {
        int ans = 0;
        for(int i = 1; i <= m; ++i)
            ans = (ans + Pow(i, n - 1) * n % mod) % mod;
        cout << ans << endl;
    }
}