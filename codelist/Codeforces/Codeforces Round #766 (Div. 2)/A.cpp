#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int n, m, r, c;
char g[509][509];
int work() {
    cin >> n >> m >> r >> c;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    if(g[r][c] == 'B') return 0;
    int ok = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= n; i++) {
        if(g[i][c] == 'B') ok = 1;
    }
    for(int i = 1; i <= m; i++) {
        if(g[r][i] == 'B') ok = 1;
    }
    if(ok == 1) return 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(g[i][j] == 'B') return 2;
        }
    }
    return -1;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case = 0;
    cin >> Case;
    while (Case--) {
        cout << work() << endl;
    }

    return 0;
}