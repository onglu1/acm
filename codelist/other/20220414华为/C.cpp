#include <bits/stdc++.h>
using namespace std;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int n, m, g[100][100], dis[100][100];
struct node {
    int x, y, d;
};
bool operator<(const node &a, const node &b) {
    return a.d > b.d;
}
priority_queue<node> q;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[1][1] = g[1][1];
    q.push({1, 1, dis[1][1]});
    while(!q.empty()) {
        int x = q.top().x, y = q.top().y;
        int d = q.top().d;
        q.pop();
        if(d > dis[x][y]) continue;
        for(int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx <= 0 || yy <= 0 || xx > n || yy > m) continue;
            if(g[xx][yy] == 0) continue;
            if(dis[x][y] + g[xx][yy] < dis[xx][yy]) {
                dis[xx][yy] = dis[x][y] + g[xx][yy];
                q.push({xx, yy, dis[xx][yy]});
            }
        }
    }
    cout << dis[n][m] << endl;
    return 0;
}