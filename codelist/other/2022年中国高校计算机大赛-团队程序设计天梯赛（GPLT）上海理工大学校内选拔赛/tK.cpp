#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int ans = 0, n;
int sum(int l, int r) {
    if((l + r) % 2 == 0) return (l + r) / 2 % mod * (r - l + 1) % mod;
    else return (r - l + 1) / 2 % mod * (l + r) % mod;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
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
    return 0;
}