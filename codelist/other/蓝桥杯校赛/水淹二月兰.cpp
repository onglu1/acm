//
// Created by onglu on 2022/3/27.
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
//const int N = 2e5 + 1009;
//const int N = 5009;
const int N = 309;
int n, m, a[N], ans, vis[N][N];
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
string s[109];
void dfs(int x, int y) {
    vis[x][y] = 1;
    ans++;
    for(int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
        if(s[xx][yy] == '#') continue;
        if(vis[xx][yy]) continue;
        dfs(xx, yy);
    }
}
void work() {
    memset(vis, 0, sizeof(vis));
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i][j] == 'S') {
                ans = 0;
                dfs(i, j);
                cout << ans - 1 << endl;
                return ;
            }
        }
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
    cin >> Case;
    while (Case--) work();
    return 0;
}