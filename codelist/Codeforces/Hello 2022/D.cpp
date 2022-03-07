#include <bits/stdc++.h>
#define int long long
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)

using namespace std;
int n, m, g[509][509];
int query(int a, int b, int c, int d) {
    if(a > c || b > d) return 0;
    return g[c][d] - g[a - 1][d] - g[c][b - 1] + g[a - 1][b - 1];
}
void work() {
    cin >> n;
    for(int i = 1; i <= 2 * n; i++) {
        for(int j = 1; j <= 2 * n; j++) {
            cin >> g[i][j];
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            ans += g[i][j];
        }
    }
    for(int i = n + 1; i <= 2 * n; i++) {
        for(int j = n + 1; j <= 2 * n; j++) {
            ans += g[i][j];
        }
    }
    int minn = 0x3f3f3f3f;
    minn = min({g[n + 1][1], g[2 * n][1],
                g[n + 1][n], g[2 * n][n],
                g[1][n + 1], g[1][2 * n],
                g[n][n + 1], g[n][2 * n]});
    cout << minn + ans << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case;
    cin >> Case;
    while (Case--) work();
    return 0;
}
