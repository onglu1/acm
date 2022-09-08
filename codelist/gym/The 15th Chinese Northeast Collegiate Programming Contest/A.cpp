//
// Created by onglu on 2022/5/18.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
#define int long long
using namespace std;
const int N = 5001 * 5000;
const int mod = 998244353;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int fac[N];
int Pow(int a, int p) {
    int ans = 1;
    for( ; p; p >>= 1, a = a * a % mod) {
        if(p & 1) {
            ans = ans * a % mod;
        }
    }
    return ans % mod;
}
int inv(int x) {
    // if(x <= 1) return 1;
    return Pow(fac[x], mod - 2);
}

int C(int n, int m) {
    if(n == 0 && m == 0) return 1;
    return fac[n] * inv(m) % mod * inv(n - m) % mod;
}
int A(int n, int m) {
    if(n == 0 && m == 0) return 1;
    return fac[n] * inv(n - m) % mod;
}
void init() {
    fac[0] = fac[1] = 1;
    for(int i = 2; i < N; i++) fac[i] = fac[i - 1] * i % mod;
}
int n, m, a[N];
int work() {
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = (ans + fac[n] * C(n * n - i, n - 1) % mod * n % mod * fac[n * n - n] % mod) % mod;
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
    init();
    int Case;
    cin >> Case;
    while(Case--)
        work();
    return 0;
}