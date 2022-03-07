#include <bits/stdc++.h>
#define int unsigned
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e6 + 1009;
const int mod = 2147483648;
int n, m, f[4009][4009];
signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    f[1][1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            f[i][j] = (1ll * f[i][j] + f[i - j][j]) % mod;
            f[i][j] = (1ll * f[i][j] + f[i - 1][j - 1]) % mod;
        }
    }
    int ans = 0;
    for(int j = 1; j <= n; j++) {
        ans = (1ll * ans + f[n][j]) % mod;
    }
    cout << (1ll * ans - 1 + mod) % mod << endl;
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}