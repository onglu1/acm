//
// Created by onglu on 2022/5/28.
//

#include <bits/stdc++.h>
#define G f[p]
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
int n, m, a[22], b[22];
int f[21][1 << 20];
void init(int p)  {
    int *g = f[p];
    for(int s = 0; s < 1 << n; s++) {
        int c = s & -s;
        int cnt = __builtin_popcount(s) - 1;
        int id = __builtin_ctz(c);
        int flag = a[id] >> p & 1;
        g[s] = g[s - c] + (flag ? ((1 << cnt) - g[s - c]) : g[s - c]);
    }
}
void work() {
    memset(f, 0, sizeof(f));
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < 21; i++) {
        init(i);
    }
    while(m--) {
        int k;
        cin >> k;
        int s = 0, flag = 0;
        for(int i = 0; i < k; i++) {
            int x;
            cin >> x;
            x -= 1;
            s |= (1 << x);
            flag ^= a[x];
        }
        int ans1 = 0;
        for(int i = 0; i < 21; i++) {
            ans1 += (1 << i) * f[i][s];
        }
        int sup = (1 << n) - 1 - s;
        int totsize = (1 << __builtin_popcount(sup));
        int ans = 0;
        for(int i = 0; i < 21; i++) {
            ans += (((flag >> i) & 1) ? totsize - f[i][sup] : f[i][sup]) * (1 << i);
        }
        cout << ans1 << " ";
        cout << ans << endl;
    }
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
    while(Case--) work();
    return 0;
}
/*
* 每一位分开来做
* f[32][S][0]表示S集合的
*/