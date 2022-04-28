//
// Created by onglu on 2022/4/15.
//

#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, a[N];
void work() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int mod;
    for(int i = 1; i <= m; i++) {
        if(i == 1) cin >> mod;
        else {
            int x;
            cin >> x;
            mod = __gcd(mod, x);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += abs(a[i]);
    }
    int od = 0, ev = 0;
    for(int i = 1; i <= mod; i++) {
        int cnt = 0, minn = abs(a[i]);
        for(int j = i; j <= n; j += mod) {
            if(a[j] < 0) {
                cnt += 1;
            }
            minn = min(minn, abs(a[j]));
        }
        if(cnt & 1) {
            od += minn;
        } else {
            ev += minn;
        }
    }
    ans -= 2 * min(od, ev);
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