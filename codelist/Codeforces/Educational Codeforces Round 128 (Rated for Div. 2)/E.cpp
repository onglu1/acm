//
// Created by onglu on 2022/5/13.
//

#include <bits/stdc++.h>

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
int f[N][2], g[N][2];
char c[2][N];
int l, r;
void work() {
    cin >> n;
    cin >> (c[0] + 1) >> (c[1] + 1);
    l = n + 10; r = -1;
    for(int i = 1; i <= n; i++) {
        if(c[0][i] == '*') l = min(l, i), r = max(r, i);
        if(c[1][i] == '*') l = min(l, i), r = max(r, i);
    }
    if(c[0][l] == '*' && c[1][l] == '*') f[l][0] = f[l][1] = 1;
    else if(c[0][l] == '*') f[l][0] = 0, f[l][1] = 1;
    else f[l][1] = 0, f[l][0] = 1;
    for(int i = l + 1; i <= r; i++) {
        if(c[0][i] == '*' && c[1][i] == '*') {
            f[i][0] = f[i][1] = min(f[i - 1][0], f[i - 1][1]) + 2;
        } else if(c[0][i] == '*') {
            f[i][0] = min(f[i - 1][0] + 1, f[i - 1][1] + 2);
            f[i][1] = min(f[i - 1][0] + 2, f[i - 1][1] + 2);
        } else if(c[1][i] == '*') {
            f[i][0] = min(f[i - 1][1] + 2, f[i - 1][0] + 2);
            f[i][1] = min(f[i - 1][1] + 1, f[i - 1][0] + 2);
        } else {
            f[i][0] = min(f[i - 1][0] + 1, f[i - 1][1] + 2);
            f[i][1] = min(f[i - 1][1] + 1, f[i - 1][0] + 2);
        }
    }
    if(c[0][r] == '*' && c[1][r] == '*') g[r][0] = g[r][1] = 1;
    else if(c[0][r] == '*') g[r][0] = 0, g[r][1] = 1;
    else g[r][1] = 0, g[r][0] = 1;
    for(int i = r - 1; i >= l; i--) {
        if(c[0][i] == '*' && c[1][i] == '*') {
            g[i][0] = g[i][1] = min(g[i + 1][0], g[i + 1][1]) + 2;
        } else if(c[0][i] == '*') {
            g[i][0] = min(g[i + 1][0] + 1, g[i + 1][1] + 2);
            g[i][1] = min(g[i + 1][0] + 2, g[i + 1][1] + 2);
        } else if(c[1][i] == '*') {
            g[i][0] = min(g[i + 1][1] + 2, g[i + 1][0] + 2);
            g[i][1] = min(g[i + 1][1] + 1, g[i + 1][0] + 2);
        } else {
            g[i][0] = min(g[i + 1][0] + 1, g[i + 1][1] + 2);
            g[i][1] = min(g[i + 1][1] + 1, g[i + 1][0] + 2);
        }
    }
    int ans = min({f[r][0], f[r][1], g[l][0], g[l][1]});
    for(int i = l; i < r; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                if(j == k) {
                    ans = min(ans, f[i][j] + g[i + 1][k] + 1);
                } else {
                    ans = min(ans, f[i][j] + g[i + 1][k] + 2);
                }
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