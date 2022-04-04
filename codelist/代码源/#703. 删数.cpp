//
// Created by onglu on 2022/4/4.
//

#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
using namespace std;
//const int N = 2e6 + 1009;
const int MT = 41;
const int N = 5e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, a[N], tp[N], b[N], t[N];
int f[N][50], g[N], ml[N][50];
int getans(int l, int r, int sgn) {
    int n = r - l + 1;
    for(int i = l; i <= r; i++) {
        a[i - l + 1] = b[i];
        if(!sgn) a[i - l + 1] = -a[i - l + 1];
    }
    tp[0] = -1;
    memset(ml[0], -1, sizeof(ml[0]));
    for(int i = 1; i <= n; i++) {
        tp[i] = a[i];
        t[i] = 0;
        while(tp[i] > 0 && tp[i] % 2 == 0) tp[i] /= 2, t[i] += 1;
        memset(ml[i], -1, sizeof(ml[i]));
        ml[i][0] = i;
        for(int j = 1; j <= MT; j++) if(ml[i][j - 1] > 0) {
            int l = ml[i][j - 1] - 1;
            if(tp[i] != tp[l]) continue;
            ml[i][j] = ml[l][t[i] + (j - 1) - t[l]];
        }
    }
    memset(f[0], 0, sizeof(f[0]));
    g[0] = 0;
    for(int i = 1; i <= n; i++) {
        memset(f[i], -1, sizeof(f[i]));
        for(int j = 0; j <= MT; j++) if(ml[i][j] != -1) {
            if(g[ml[i][j] - 1] == -1) continue;
            f[i][j] = g[ml[i][j] - 1] + 1;
        }
        g[i] = -1;
        for(int j = 0; j <= MT; j++) if(f[i][j] != -1) {
                if(g[i] == -1) g[i] = f[i][j];
                else g[i] = min(g[i], f[i][j]);
            }
    }
    return g[n];
}
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++) {
        b[i] = a[i + 1] - a[i];
    }
    n -= 1;
    int ans = 0;
    for(int i = 1; i <= n; ) {
        if(b[i] == 0) ans++;
        while(i <= n && b[i] == 0) i++;
        if(i <= n) {
            int j = i + 1;
            int sgn = b[i] > 0;
            while(j <= n && b[j] != 0 && (b[j] > 0) == sgn) j++;
            ans += getans(i, j - 1, sgn);
//            cout << " ? " << ans << endl;
            i = j;
        }
    }
    cout << ans + 1 << endl;

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