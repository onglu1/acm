#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, s1 = 0, s2 = 0, t = 0;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        t += x;
        s1 += (m * (k - 1) % k - x + k) % k;
    }
    for(int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        t -= x;
        s2 += (n * (k - 1) % k - x + k) % k;
    }
    if(t % k != 0) {
        cout << -1 << endl;
    } else cout << n * m * (k - 1) - max(s1, s2) << endl;
    return 0;
}