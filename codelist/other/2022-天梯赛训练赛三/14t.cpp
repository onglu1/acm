//
// Created by onglu on 2022/3/12.
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
//const int N = 309
int n, m, a[N], f[N][4];
int fac[N];
int C(int n, int m) {
    if(m == 0) return 1;
    else if(m == 1) return n;
    else if(m == 2) return n * (n - 1) / 2;
    else if(m == 3) return n * (n - 1) / 2 * (n - 2) / 3;
}
string s;
int get(int n) {
    return f[n][0] + f[n][1] + f[n][2] + f[n][3];
}
void work() {
    cin >> s;
    a[n = 1] = 1;
    for(int i = 2; i <= s.size(); i++) {
        if(s[i - 1] != s[i - 2]) {
            a[++n] = 1;
        } else {
            a[n]++;
        }
    }
    f[1][0] = C(a[1], 0);
    f[1][1] = C(a[1], 1);
    if(a[1] >= 2) f[1][2] = C(a[1], 2);
    if(a[1] >= 3) f[1][3] = C(a[1], 3);
    for(int i = 2; i <= n; i++) {
        int g[4] = {0};
        memcpy(g, f[i - 1], sizeof(f[i - 1]));
        for(int j = 0; j <= a[i] && j <= 3; j++) {
            for(int k = 0; k + j <= 3; k++) {
                g[j + k] += f[i - 1][k] * C(a[i], j);
            }
        }
        memcpy(f[i], g, sizeof(g));
    }
    cout << get(n)<< endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    work();
    return 0;
}