//
// Created by onglu on 2022/3/26.
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
const int mod = 998244353;
int n, m, a[N];
int sum(int l, int r) {
    if((l + r) % 2 == 0) return (l + r) / 2 % mod * (r - l + 1) % mod;
    else return (r - l + 1) / 2 % mod * (l + r) % mod;
}
void work() {
    int ans = 0;
    cin >> n;
    for(int l = 1; l <= n; l++) {
        int r = n / (n / l);
        int t = (n / l) % mod;
        ans += (n % mod * ((r - l + 1) % mod)) % mod;
        ans -= t * sum(l, r) % mod;
        ans = (ans % mod + mod) % mod;
        l = r;
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
//    cin >> Case;
    while (Case--) work();
    return 0;
}