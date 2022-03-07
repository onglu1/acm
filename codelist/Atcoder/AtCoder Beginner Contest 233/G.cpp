#include <bits/stdc++.h>

#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)

using namespace std;
int n, ans[51][51][51][51];
int g[59][59];
char c[59][59];
int get(int x, int y, int xx, int yy) {
    if(x > xx || y > yy) return 0;
    return g[xx][yy] - g[x - 1][yy] - g[xx][y - 1] + g[x - 1][y - 1];
}
int query(int x, int y, int xx, int yy) {
    if(ans[x][y][xx][yy] != -1) return ans[x][y][xx][yy];
    if(get(x, y, xx, yy) == 0) return ans[x][y][xx][yy] = 0;
    int minncost = 0x3f3f3f3f;
    for(int i = x; i + 1 <= xx; i++) {
        minncost = min(minncost, query(x, y, i, yy) + query(i + 1, y, xx, yy));
    }
    for(int i = y; i + 1 <= yy; i++) {
        minncost = min(minncost, query(x, y, xx, i) + query(x, i + 1, xx, yy));
    }
    if(xx - x == yy - y) {
        minncost = min(minncost, xx - x + 1);
    }
    return ans[x][y][xx][yy] = minncost;
}
signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(ans, -1, sizeof(ans));
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> (c[i] + 1);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            g[i][j] = g[i - 1][j] + g[i][j - 1]- g[i - 1][j - 1] + (c[i][j] == '#');
        }
    }
    cout << query(1, 1, n, n) << endl;
    return 0;
}
