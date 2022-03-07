#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 5e5 + 1009;
int n, m, a[N];
struct Edge {
    int to, w;
};
struct node {
    int t, d, k, x;
} dis[N];
bool operator<(const node &a, const node &b) {
    if(a.t != b.t) return a.t > b.t;
    if(a.d != b.d) return a.d < b.d;
    return a.k < b.k;
}
bool operator<=(const node &a, const node &b) {
    if(a.t != b.t) return a.t > b.t;
    if(a.d != b.d) return a.d < b.d;
    return a.k <= b.k;
}
vector<Edge> ver[N];
void dijkstra(int s) {
    priority_queue<node> q;
    dis[n].x = -1;
    for(int i = 1; i <= n; i++) dis[i].t = (1ll << 61);
    dis[0] = {0, 0, a[0], s};
    q.push({0, 0, a[0], s});
    while(q.size()) {
        node x = q.top();
        q.pop();
//        cout << x.x << endl;
        if(x < dis[x.x]) continue;
        for(auto e : ver[x.x]) {
            node t = x;
            t.x = e.to;
            t.t += e.w;
            t.d += 1;
            t.k += a[e.to];
            if(!(t <= dis[e.to])) {
                dis[e.to] = t;
                q.push(dis[e.to]);
            }
        }
    }
}
signed main() {
//    freopen("easy.in", "r", stdin);
//    freopen("easy.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int j = 1; j <= m; j++) {
        int x, y, w;
        cin >> x >> y >> w;
        ver[x].push_back({y, w});
        ver[y].push_back({x, w});
    }
    dijkstra(1);
    if(dis[n].x == -1) cout << -1 << endl;
    else cout << dis[n].d << " " << dis[n].t << " " << dis[n].k << endl;

    return 0;
}