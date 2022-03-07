#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e5 + 1009;
int v[N];
int n, a[N], b[N];
int c[N], d[N], pre[N];
int fid(int x) {
    return pre[x] == x ? x : (pre[x] = fid(pre[x]));
}
signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = 0;
    for(int i = 1; i <= n; i++) a[n + 1] ^= a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    b[n + 1] = 0;
    for(int i = 1; i <= n; i++) b[n + 1] ^= b[i];

    for(int i = 1; i <= n + 1; i++) c[i] = a[i], d[i] = b[i];
    sort(c + 1, c + 1 + n + 1); sort(d + 1, d + 1 + n + 1);
    for(int i = 1; i <= n + 1; i++) {
        if(c[i] != d[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    vector<int> tt;
    for(int i = 1; i <= n + 1; i++) {
        if (a[i] != b[i] || i == n + 1) {
            tt.push_back(a[i]);
            tt.push_back(b[i]);
        }
    }
    sort(tt.begin(), tt.end());
    tt.resize(unique(tt.begin(), tt.end()) - tt.begin());
    for(int i = 0; i < tt.size(); i++) pre[i] = i;
    int ans = 0;
    for(int i = 1; i <= n + 1; i++) {
        if(a[i] != b[i]) {
            if(i < n + 1)
                ans ++;
            int x = lower_bound(tt.begin(), tt.end(), a[i]) - tt.begin();
            int y = lower_bound(tt.begin(), tt.end(), b[i]) - tt.begin();
            pre[fid(x)] = fid(y);
        }
    }
//    cout << ans << endl;
    if(ans == 0) {
        printf("0\n");
        return 0;
    }
    for(int i = 0; i < tt.size(); i++)
        if(fid(i) == i){
//            cout << tt[i << endl;
            ans++;
        }
    cout << ans - 1 << endl;
    return 0;
}