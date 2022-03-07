#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
struct node {
    int x, y, d;
};
bool operator<(const node &a, const node &b) {
    return a.d > b.d;
}
int dis[509][509];
map<int, map<int, int> > g;
int n, m;
priority_queue<node> q;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int get(int x, int y) {
    return (x - 1) * (n + 1) + y;
}
void work() {
    cin >> m >> n;
    g.clear();
    for(int i = 1; i <= m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a == c && b > d) swap(b, d);
        if(b == d && a > c) swap(a, c);
        int p1, p2;
        if(a == c) {
            p1 = (a - 1) * (n + 1) + b + 1;
            p2 = a * (n + 1) + b + 1;
            g[p1][p2]++;
            g[p2][p1]++;
//            cout << "1 : " << p1 << " " << p2 << endl;
            p1 = (n + 1) * (n + 1) - p1 + 1;
            p2 = (n + 1) * (n + 1)  - p2 + 1;
            g[p1][p2]++;
            g[p2][p1]++;
//            cout << "2 : " << p1 << " " << p2 << endl;
        } else {
            p1 = a * (n + 1) + b;
            p2 = a * (n + 1) + b + 1;
            g[p1][p2]++;
            g[p2][p1]++;
            p1 = (n + 1) * (n + 1)  - p1 + 1;
            p2 = (n + 1) * (n + 1)  - p2 + 1;
            g[p1][p2]++;
            g[p2][p1]++;
        }
    }
    for(int i = 1; i <= n + 1; i++) {
        memset(dis[i], 0x3f, sizeof(int) * (n + 5));
    }
    dis[n / 2 + 1][n / 2 + 1] = 0;
    while(q.size()) q.pop(); q.push({n / 2 + 1, n / 2 + 1, 0});
    while(q.size()) {
        int x = q.top().x, y = q.top().y;
        int d = q.top().d;
        q.pop();
        if(dis[x][y] < d) continue;
        for(int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx < 0 || xx > n + 1) continue;
            if(xx < 0 || yy > n + 1) continue;
            if(dis[xx][yy] > dis[x][y] + g[get(x, y)][get(xx, yy)]) {
                dis[xx][yy] = dis[x][y] + g[get(x, y)][get(xx, yy)];
                q.push({xx, yy, dis[xx][yy]});
            }
        }
    }
//    cout << g[8][3] << endl;
    int ans =  0x3f3f3f3f;
    for(int i = 1; i <= n + 1; i++) {
        ans = min(ans, dis[1][i]);
        ans = min(ans, dis[n + 1][i]);
        ans = min(ans, dis[i][1]);
        ans = min(ans, dis[i][n + 1]);
    }
    cout << m - ans << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case = 0;
    cin >> Case;
    while (Case--) work();
    return 0;
}