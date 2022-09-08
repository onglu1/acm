//
// Created by onglu on 2022/5/9.
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
string s;
int f[N][2], g[N][2];
void work() {
    cin >> n;
    cin >> s;
    g[0][0] = g[0][1] = 1;
    int t = s[0] - '0';
    if(s[0] == s[1]) {
        f[0][t] = 0;
        f[0][1 - t] = 2;
    } else {
        f[0][t] = 1;
        f[0][1 - t] = 1;
    }
    for(int i = 1; i * 2 + 1 < n; i++) {
        t = s[i * 2] - '0';
        if(s[i * 2] == s[i * 2 + 1]) {
            f[i][t] = min(f[i - 1][0], f[i - 1][1]);
            f[i][1 - t] = min(f[i - 1][0], f[i - 1][1]) + 2;
        } else {
            f[i][t] = min(f[i - 1][0], f[i - 1][1]) + 1;
            f[i][1 - t] = min(f[i - 1][0], f[i - 1][1]) + 1;
        }
        if(f[i - 1][0] == f[i - 1][1]) {
            g[i][t] = min(g[i - 1][t], g[i - 1][1 - t] + 1);
            g[i][1 - t] = min(g[i - 1][t] + 1, g[i - 1][1 - t]);
        } else if(f[i - 1][0] < f[i - 1][1]) {
            g[i][t] = g[i - 1][0] + (t != 0);
            g[i][1 - t] = g[i - 1][0] + (t != 1);
        } else {
            g[i][t] = g[i - 1][1] + (t != 1);
            g[i][1 - t] = g[i - 1][1] + (t != 0);
        }
    }
    if(f[n / 2 - 1][0] == f[n / 2 - 1][1]) cout << f[n / 2 - 1][1] << " " << min(g[n / 2 - 1][1], g[n / 2 - 1][0]) << endl;
    else if(f[n / 2 - 1][0] < f[n / 2 - 1][1]) cout << f[n / 2 - 1][0] << " " << g[n / 2 - 1][0] << endl;
    else if(f[n / 2 - 1][0] > f[n / 2 - 1][1]) cout << f[n / 2 - 1][1] << " " << g[n / 2 - 1][1] << endl;
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