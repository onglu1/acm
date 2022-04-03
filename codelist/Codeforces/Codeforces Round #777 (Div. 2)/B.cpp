//
// Created by onglu on 2022/3/25.
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
//const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
const int N = 309;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m, a[N];
int f[N][N], g[N][N];
int check(int xx, int yy) {
    return 1 <= xx && xx <= n && 1 <= yy && yy <= m;
}
void dfs(int x, int y, int c) {
    f[x][y] = c;
    for(int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(check(xx, yy) && !f[xx][yy] && g[xx][yy]) {
            dfs(xx, yy, c);
        }
    }
}
void work() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++) {
            g[i][j] = s[j - 1] == '1';
        }
    }
    memset(f, 0, sizeof(f));
    int c = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) if(g[i][j] == 1 && f[i][j] == 0) {
            dfs(i, j, ++c);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) if(g[i][j] == 0) {
            for(int t = 0; t < 4; t++) {
                int tt = (t + 1) % 4;
                int x = i + dx[t];
                int y = j + dy[t];
                int xx = i + dx[tt];
                int yy = j + dy[tt];
                if(!check(xx, yy) || !check(x, y)) continue;
                if(!f[xx][yy] || !f[x][y]) continue;
                if(f[x][y] == f[xx][yy]) {
                    cout << "NO" << endl;
                    return ;
                }

            }
        }
    }
    cout << "YES" << endl;
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