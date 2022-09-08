//
// Created by onglu on 2022/5/8.
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
int n, m, a[N];
int f[5009][5009];
int query(int l, int r) {
    if(l > r) return 0;
    if (r >= n - 1) return 0;
    int ans = 0;
//    for(int i = l; i <= r; i++) ans += f[i][r + 2];
//    return ans;
    return f[r][r + 2] - f[l - 1][r + 2];
}
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        f[i][n] = a[n] < a[i];
        for(int j = n - 1; j >= i + 1; j--) {
            f[i][j] = f[i][j + 1] + (a[j] < a[i]);
        }
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            f[i][j] += f[i - 1][j];
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(a[j] > a[i]) {
                ans += query(i + 1, j - 1);
            }
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