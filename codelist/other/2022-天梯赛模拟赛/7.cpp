//
// Created by onglu on 2022/4/18.
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
int k, x, g[109][109];
void move(int j, int k) {
    for(int i = n; i >= 1; i--) {
        if(i > k) {
            g[i][j] = g[i - k][j];
        } else {
            g[i][j] = x;
        }
    }
}
void work() {
    cin >> n >> k >> x;
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }
    int now = 1;
    for(int j = 1; j <= n; j++) {
        if(j & 1) continue;
        move(j, now);
        now = now % k + 1;
    }
    for(int i = 1; i <= n; i++) {
        int s = 0;
        for(int j = 1; j <= n; j++) {
            s += g[i][j];
        }
        cout << s << " \n"[i == n];
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
    while (Case--) work();
    return 0;
}