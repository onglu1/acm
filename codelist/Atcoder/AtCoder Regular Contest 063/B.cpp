#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e5 + 1009;
int n, t, a[N], b[N];
signed main() {
//#ifndef ONLINE_JUDGE
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);
//#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int maxn = 0;
    int v = -1;
    for(int i = n; i >= 1; i--) {
        maxn = max(maxn, a[i]);
        b[i] = maxn - a[i];
        v = max(v, b[i]);
    }
    int ans = 0, tmp = 0;
    for(int i = 1; i <= n; i++) {
        if(b[i] == v) {
            ans++;
        }
    }
//    cout << ans << endl;
    v = -1;
    maxn = 0x3f3f3f3f;
    for(int i = 1; i <= n; i++) {
        maxn = min(maxn, a[i]);
        b[i] = a[i] - maxn;
        v = max(v, b[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(b[i] == v) {
            tmp++;
        }
    }
    ans = min(ans, tmp);
    cout << ans << endl;
    return 0;
}