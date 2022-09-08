#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m;
char mp[1009][1009];
int dis[1009][1009][4];
struct node {
    pair<int, int> pos;
    int dir, dis;
};
bool operator<(const node &a, const node &b) {
    return a.dis > b.dis;
}
priority_queue<node> q;
int out_bound(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}
signed main() {
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> mp[i];
    int sx, sy, tx, ty;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)  {
            if(mp[i][j] == 'S') {sx = i, sy = j;}
            if(mp[i][j] == 'E') {tx = i, ty = j;}
            for(int k = 0; k < 4; k++) dis[i][j][k] = n * m * 4;
        }
    }
    for(int k = 0; k < 4; k++) {
        dis[sx][sy][k] = 0;
        q.push({{sx, sy}, k, 0});
    }
    while(q.size()) {
        int x = q.top().pos.first;
        int y = q.top().pos.second;
        int dir = q.top().dir;
        int d = q.top().dis;
        q.pop();
        if(dis[x][y][dir] < d) continue;
        for(int i = 0; i < 4; i++) {
            int nxtx = x + dx[i];
            int nxty = y + dy[i];
            if(out_bound(nxtx, nxty) || mp[nxtx][nxty] == 'X') continue;
            int nxtd = d + 1 + (dir != i);
            if(nxtd < dis[nxtx][nxty][i]) {
                dis[nxtx][nxty][i] = nxtd;
                q.push({{nxtx, nxty}, i, nxtd});
            }
        }
    }
    int t = *min_element(dis[tx][ty], dis[tx][ty] + 4);
    if(t >= n * m * 4) t = -1;
    cout << t;
    return 0;
}


