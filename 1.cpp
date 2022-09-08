#include <bits/stdc++.h>
using namespace std;
int n, m;
char g[1009][1009];
int dis[1009][1009][4];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
struct node {
    int x, y, i, d;
};
bool operator<(const node &a, const node &b) {
    return a.d > b.d;
}
priority_queue<node> q;
signed main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> g[i];
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)  {
            if(g[i][j] == 'S') {
                for(int k = 0; k < 4; k++) {
                    dis[i][j][k] = 0;
                    q.push({i, j, k, 0});
                }
            }
        }
    }
    while(q.size()) {
        int x = q.top().x;
        int y = q.top().y;
        int dir = q.top().i;
        int d = q.top().d;
        q.pop();
        if(dis[x][y][dir] < d) continue;
        for(int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
            if(g[xx][yy] == 'X') continue;
            int dd = d + 1;
            if(dir != i) dd += 1;
            if(dd < dis[xx][yy][i]) {
                dis[xx][yy][i] = dd;
                q.push({xx, yy, i, dd});
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] == 'E') {
                int minn = dis[i][j][0];
                for(int k = 0; k < 4; k++) {
                    minn = min(minn, dis[i][j][k]);
                }
                if(minn == 0x3f3f3f3f) cout << -1 << endl;
                else cout << minn << endl;
                return 0;
            }
        }
    }
    return 0;
}