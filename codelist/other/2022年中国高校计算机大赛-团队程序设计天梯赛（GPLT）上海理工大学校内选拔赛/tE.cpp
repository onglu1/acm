#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 0x3f3f3f3f;
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int n, m, ans = INF, ans2 = INF, num;
int k, a, b, c, d;
int vis[301][301], vis2[301][301];
int mp[301][301];
void dfs1(int x, int y, int temp) {
    if (x > n || y > m || x < 0 || y < 0) return;
    vis[x][y] = 1;
    if (x == c && y == d) {
        ans = min(ans, temp);
        return;
    }
    for (int i = 0; i < 8; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 0 || xx > n || yy < 0 || yy > m) continue;
        if (vis[xx][yy]) continue;
        dfs1(xx, yy, temp + 1);
    }
}
void dfs2(int x, int y, int temp) {
    if (x > n || y > m || x < 0 || y < 0) return;
    vis[x][y] = 1;
    num--;
    if (x == c && y == d) {
        ans2 = min(ans, temp);
        return;
    }
    if (num == 0) {
        ans2 = -1;
        return;
    }
    int ttt = 8;
    for (int i = 0; i < 8; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 0 || xx > n || yy < 0 || yy > m) continue;
        //if (vis2[xx][yy]) continue;
        int f = 0;
        for (int jx = min(x,xx); jx <= max(x,xx); jx++) {
            for (int jy = min(y,yy); jy <= max(y,yy); jy++) {
                if (mp[jx][jy]){
                    f = 1;
                    break;
                }
            }
            if (f) break;
        }
        if (f) continue;
        ttt--;
        dfs2(xx, yy, temp + 1);
    }
    if (ttt == 8) {
        ans2 = -1;
        return;
    }

}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        memset(vis, 0, sizeof(vis));
        memset(vis2, 0, sizeof(vis));
        memset(mp,0,sizeof(mp));
        cin >> n >> m >> k >> a >> b >> c >> d;
        ans = INF, ans2 = INF;
        while (k--) {
            int x, y;
            cin >> x >> y;
            mp[x][y] = 1;
            vis2[x][y] = 1;
        }
        dfs1(a, b, 0);
        dfs2(a, b, 0);
        cout << ans << " " << ans2 << "\n";
    }

    return 0;
}