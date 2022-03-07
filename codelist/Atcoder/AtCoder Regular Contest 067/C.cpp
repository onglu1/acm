#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e6 + 1009;
int n, m, a, b, c, d, f[3009], g[3009];
int fac[N], inv[N];
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
int Pow(int a, int p) {
    int ans = 1;
    for( ; p; p >>= 1, a = a * a % mod)
        if(p & 1)
            ans = ans * a % mod;
    return ans;
}
int get(int n, int m, int k) {
    return fac[n] * Pow(Pow(fac[k], m) * fac[n - m * k] % mod * fac[m] % mod, mod - 2) % mod;
}
int getlimitat(int c, int d) {
    if(c == 0) return 0;
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for(int i = b; i >= a; i--) {
        memset(g, 0, sizeof(g));
        for(int j = 0; j < i; j++) {
            int adder = 0;
            for(int k = j; k <= n; k += i) {
                for(int p = c; p <= d && p * i + k <= n; p++) {
                    g[k + p * i] = (g[k + p * i] + f[k] * get(n - k, p, i) % mod) % mod;
                }
            }
        }
        for(int j = 0; j <= n; j++) f[j] = (f[j] + g[j]) % mod;
        f[0] = 1;
    }
    return f[n];
}
signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    cin >> n >> a >> b >> c >> d;
    cout << getlimitat(c, d) << endl;
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}
/*
 * 把组从大到小枚举
 * f[i][j]表示剩余i个人，现在大小枚举到了j的方案数
 * 考虑当前这个大小的组放多少个人。
 * C和D的限制很烦，考虑容斥？
 * 全部小于D的限制方案数减去全部小于C的限制
 * 枚举同余系
 */