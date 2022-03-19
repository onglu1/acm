//
// Created by onglu on 2022/3/16.
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
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N];
int x[N], y[N];
int g[20][20], f[20][20];
signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    n = 4;
    x[1] = 20; y[1] = 25;
    x[2] = 25; y[2] = 10;
    x[3] = 10; y[3] = 5;
    x[4] = 5; y[4] = 15;
    memset(f, 0x3f, sizeof(f));
    for(int i = 1; i + 1 <= n; i++) {
        f[i][i] = 0;
        f[i][i + 1] = x[i] * y[i] * y[i + 1];
    }
    f[n][n] = 0;
    for(int len = 3; len <= n; len++) {
        for(int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            for(int k = i; k < j; k++) {
                if(f[i][k] + f[k + 1][j] + x[i] * y[k] * y[j] < f[i][j]) {
                    f[i][j] = f[i][k] + f[k + 1][j] + x[i] * y[k] * y[j];
                    g[i][j] = k;
                }
            }
        }
    }
    cout << f[1][n] << endl;
    cout << g[1][n] << endl;
    return 0;
}