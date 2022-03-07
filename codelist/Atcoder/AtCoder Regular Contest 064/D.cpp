#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e6 + 1009;
int n, k, f[N];
vector<int> pri;
int Pow(int a, int p) {
    int ans = 1;
    for( ; p; p >>= 1, a = a * a % mod)
        if(p & 1)
            ans = ans * a % mod;
    return ans % mod;
}
signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i * i <= n; i++) if(n % i == 0) {
        pri.push_back(i);
        if(i * i != n) {
            pri.push_back(n / i);
        }
    }
    sort(pri.begin(), pri.end());
    int ans = 0;
    for(int i = 0; i < pri.size(); i++) {
        f[i] = Pow(k, (pri[i] + 1) / 2);
        for(int j = 0; j < i; j++) if(pri[i] % pri[j] == 0) f[i] = (f[i] + mod - f[j]) % mod;
        if(pri[i] & 1) ans = (ans + f[i] * pri[i] % mod) % mod;
        else ans = (ans + f[i] * (pri[i] / 2) % mod) % mod;
    }
    cout << ans << endl;
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}
/*
 * 就是前面一个回文串 然后后面一坨两个的
 *
 */