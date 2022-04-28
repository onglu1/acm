//
// Created by onglu on 2022/4/27.
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
int sum, cnt;
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    cnt = sum - sum / n * n;
    int res1 = cnt, res2 = n - cnt;
    int ans = 0, t = sum / n;
    for(int i = 1; i <= n; i++) {
        if(a[i] > t) {
            if(res1) ans += a[i] - t - 1, res1 -= 1;
            else ans += a[i] - t, res2 -= 1;
        } else {
            if(res2) ans += t - a[i], res2 -= 1;
            else ans += t + 1 - a[i], res1 -= 1;
        }
    }
    cout << ans / 2 << endl;
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