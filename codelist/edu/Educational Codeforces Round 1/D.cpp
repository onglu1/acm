//
// Created by onglu on 2022/4/24.
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
const int N = 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, q, a[N];
int g[N][N], ans, vis[N][N];
int col[N][N];
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};
void dfs(int x, int y) {
    if(vis[x][y]) return ;
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(!g[xx][yy]) ans++;
        else {
            dfs(xx, yy);
        }
    }
}
void fil(int x, int y) {
    if(col[x][y]) return ;
    col[x][y] = ans;
    for(int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(g[xx][yy])
            fil(xx, yy);
    }
}
void work() {
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++) {
            g[i][j] = s[j - 1] == '.';
        }
    }
    for(int i = 1; i <= n; i++) {

        for(int j = 1; j <= m; j++) if(g[i][j] && !vis[i][j]) {
            ans = 0;
            dfs(i, j);
            fil(i, j);
        }
    }
    for(int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        cout << col[x][y] << endl;
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