//
// Created by onglu on 2022/2/28.
//

#include <bits/stdc++.h>

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
const int mod = 1e9 + 7;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, p, a[N], f[N];
map<int, int> M;
void work() {
    M.clear();
    cin >> n >> p;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) {
        int t = a[i], ok = 0;
        if(p <= 31 && a[i] >= (1 << p)) continue;
        while(t) {
            if(M.count(t)) {
                ok = 1;
                break;
            }
            if(t & 1) t = (t - 1) / 2;
            else if(t % 4 != 0) break;
            else t /= 4;
        }
        if(ok == 1) continue;
        M[a[i]] = 1;
        int len = 0;
        t = a[i];
        while(t) {
            len++;
            t /= 2;
        }
        ans = (ans + f[p - len]) % mod;
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
    f[0] = 1; f[1] = 1;
    for(int i = 2; i < N; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    }
    for(int i = 1; i < N; i++) {
        f[i] = (f[i] + f[i - 1]) % mod;
    }
    while (Case--) work();
    return 0;
}