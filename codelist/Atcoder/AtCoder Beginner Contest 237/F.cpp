//
// Created by onglu on 2022/2/25.
//

#include <bits/stdc++.h>

#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
//const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
const int N = 1009;
//const int N = 309
const int mod = 998244353;
int n, m, f[N][20][20][20];

void work() {
    cin >> n >> m;
    f[0][m + 1][m + 1][m + 1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m + 1; j++) {
            for(int k = j; k <= m + 1; k++) {
                for(int q = k; q <= m + 1; q++) {
                    for(int p = 1; p <= m; p++) {
                        int ns1 = j, ns2 = k, ns3 = q;
                        if(p > q) continue;
                        if(p > k) ns3 = min(ns3, p);
                        if(p > j) ns2 = min(ns2, p);
                        ns1 = min(ns1, p);
                        f[i][ns1][ns2][ns3] = (f[i][ns1][ns2][ns3] + f[i - 1][j][k][q]) % mod;
                    }
                }

            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 1; k <= m; k++) {
                ans = (ans + f[n][i][j][k]) % mod;
            }

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
/*
 * f[i][s1][s2]表示前i个，长度为1的数字的最小值是s1，长度为2的最小值为s2
 *
 *
 */