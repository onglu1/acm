//
// Created by onglu on 2022/3/25.
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
const int mod = 998244353;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N];
#define ll long long
void work() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 1;
    for(int i = 0; i < n; i++) {
        ans = ans * ((m / a[i]) % mod) % mod;
    }
    for(int s = 1; s < 1 << n; s++) {
        if(__builtin_popcount(s) <= 1) continue;
        int lcm = 1, f = -1, del = 1;
        for(int i = 0; i < n; i++) {
            if(s >> i & 1) {
                if(log(lcm) + log(a[i]) - log(__gcd(lcm, a[i])) > log(m)) {
                    f = 0;
                    break;
                }
                f = -f;
                lcm = lcm / __gcd(lcm, a[i]) * a[i];
            } else {
                del = del * ((m / a[i]) % mod) % mod;
            }
        }
        del = del * ((m / lcm)  % mod) % mod;
        ans = ((ans + del * f) % mod + mod) % mod;
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
//  cin >> Case;
    while (Case--) work();
    return 0;
}