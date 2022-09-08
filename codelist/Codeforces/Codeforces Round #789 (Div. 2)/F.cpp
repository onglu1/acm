//
// Created by onglu on 2022/5/10.
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
//const int N = 309;
int n, m, a[N];
int k;
void work() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = n - k + 1; i <= n; i++) {
        if(a[i] != 0 && a[i] != -1) {
            cout << 0 << endl;
            return ;
        }
    }
    int ans = 1;
    for(int i = 1; i <= k; i++) {
        ans = ans * i % mod;
    }
    for(int i = 1; i <= n - k; i++) {
        if(a[i] == -1) ans = ans * (i + k) % mod;
        else if(a[i] == 0) {
            ans = ans * (k + 1) % mod;
        }
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
    cin >> Case;
    while (Case--) work();
    return 0;
}