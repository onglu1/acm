//
// Created by onglu on 2022/3/27.
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
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
const int mod = 1e9 + 7;
int n, m, a[N], pw[N];
int f[3009][3009], g[3009][3009], sum[3009][3009];
void work() {
    cin >> n >> m;
    f[n + 1][0] = 1;
    sum[n + 1][0] = 1;
//    for(int i = 0; i <= n; i++) {
//        sum[n + 1][i] = 1;
//    }
    for(int i = n; i >= 1; i--) {
        for(int j = n - i; j >= 0; j--) {
            if(j + 1 <= n - i)
                f[i][j] = f[i][j + 1];

            f[i][j] = (f[i][j] + sum[i + 1][j]) % mod;
            g[i][j] = sum[i + 1][j];
//            for(int k = i + 1; k <= n + 1 && j - (k - i - 1) >= 0; k++) {
//                f[i][j] = (f[i][j] + f[k][j - (k - i - 1)]) % mod;
//            }
        }
        sum[i][0] = f[i][0];
        for(int j = 1; j <= n; j++) {
            sum[i][j] = (sum[i + 1][j - 1] + f[i][j]) % mod;
        }
    }
    int ans = 0;
    pw[0] = 1;
    for(int i = 1; i <= n; i++) pw[i] = pw[i - 1] * 2 % mod;
    if(n - m - 1 >= 0) cout << g[1][n - m] * pw[n - m - 1] % mod  << endl;
    else cout << g[1][n - m] % mod  << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
//    cin >> Case;
    while (Case--) work();
    return 0;
}
/*
 * f[i][k]表示i张卡牌 1第k个的方案数
 * 转移：考虑这张卡牌插在哪里，方案显然对称
 * 或者从吃开始考虑，假如我们第一个吃i，那么再对面的一定是i -> n的一个顺序插入
 * f[i][j]表示现在吃到i，另一边比i大的还有j个没吃的方案数
 * f[i][j] = sum(f[k][j - (k - i - 1)])
 * f[n + 1][0] = 1
 *
 *
 */