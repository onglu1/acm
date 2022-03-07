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
int mod;
int f[N];
int Pow(int a, int p) {
    int ans = 1;
    for( ; p; p >>= 1, a = a * a % mod)
        if(p & 1)
            ans = ans * a % mod;
    return ans;
}
signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> mod;
    f[1] = 1;
    f[2] = 2;
    f[3] = 3 * Pow(2, mod - 2) % mod;
//    f[4] =
    cout << f[n] << endl;
    return 0;
}