//
// Created by onglu on 2022/3/5.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define int long long
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
int f[2][20];
const int mod = 998244353;

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= 9; i++)
        f[1][i] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= 9; j++) {
            f[i & 1][j] = (f[(i - 1) & 1][j] + f[(i - 1) & 1][j - 1] + f[(i - 1) & 1][j + 1]) % mod;
        }
    }
    int ans = 0;
    for(int i = 1; i <= 9; i++) {
        ans = (ans + f[n & 1][i]) % mod;
    }
    cout << ans << endl;
    return 0;
}