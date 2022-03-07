#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e5 + 1009;
int n, m, q, w[N];
int dis[101][N];
vector<int> ver[N];
void bfs(int p) {
    memset(dis[p], -1, sizeof(int) * (n + 209));
    dis[p][p] = 0;
    queue<int> q;
    for(auto x : ver[p]) {
        dis[p][x] = 0;
        q.push(x);
    }
    while(q.size()) {
        int x = q.front(); q.pop();
        for(auto y : ver[x]) {
            if(dis[p][y] != -1) continue;
            dis[p][y] = dis[p][x] + 1;
            q.push(y);
        }
    }
}
signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
        for(int j = w[i]; j <= 100; j++) {
            ver[j].push_back(i + 100);
        }
    }
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        x += 100; y += 100;
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    for(int i = 1; i <= 100; i++) {
        bfs(i);
    }
//    for(int i = 1; i <= n; i++) {
//        cout << dis[2][i + 100] << endl;
//    }
    for(int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        cout << dis[y][x + 100] << endl;
    }
    return 0;
}