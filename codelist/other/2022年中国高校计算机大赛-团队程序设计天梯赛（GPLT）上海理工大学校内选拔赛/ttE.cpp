#include <bits/stdc++.h>
using namespace std;
const int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
int n, m, ans, ans2, num;
int k, a, b, c, d;
int vis[321][321], mp[321][321];
queue<pair<int, int> > q;
void bfs(int x, int y, int isCh) {
    memset(vis, -1, sizeof(vis));
    while(q.size()) q.pop();
    q.push({x, y});
    vis[x][y] = 0;
    while(q.size()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx <= 0 || xx > n || yy <= 0 || yy > m) continue;
            if (vis[xx][yy] != -1 || mp[xx][yy]) continue;
            if (isCh && mp[x + dx[i] / 2][y + dy[i] / 2]) continue;
            vis[xx][yy] = vis[x][y] + 1;
            q.push({xx, yy});
        }
    }
    ans = vis[c][d];
}
signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        memset(mp,0,sizeof(mp));
        cin >> n >> m >> k >> a >> b >> c >> d;
        while (k--) {
            int x, y;
            cin >> x >> y;
            mp[x][y] = 1;
        }
        bfs(a, b, 0);
        bfs(a, b, 1);
        cout << ans << " " << ans2 << "\n";
    }
    return 0;
}