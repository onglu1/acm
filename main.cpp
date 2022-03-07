//
// Created by onglu on 2022/3/5.
//

#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
using namespace std;
const int N = 2e6 + 1009;
struct edge {
    int y, d;
};
struct node {
    int x, d;
};
bool operator<(const node &a, const node &b) {
    return a.d > b.d;
}
int n, m, p, a[N];
void dijkstra(int s, vector<edge> *ver, int *dis) {
    priority_queue<node> q;
    while(!q.empty()) q.pop(); q.push({s, 0});
    for(int i = 1; i <= n; i++) dis[i] = (1ll << 62) - 1;
    dis[s] = 0;
    while(!q.empty()) {
        int x = q.top().x, d = q.top().d;
        q.pop();
        if(d > dis[x]) continue;
        for(auto e : ver[x]) {
            if(dis[e.y] > dis[x] + e.d) {
                dis[e.y] = dis[x] + e.d;
                q.push({e.y, dis[e.y]});
            }
        }
    }
}
vector<edge> ver[N];
vector<edge> rver[N];
int dis[N], rdis[N];
int tree[N];
int cal(int x, int y) {
    if(x == 0) return 0;
    else return (x - 1) / y + 1;
}
void update(int rt) {
    tree[rt] = min(tree[lson], tree[rson]);
}
void build(int l, int r, int rt) {
    if(l == r) {
        tree[rt] = dis[l] + cal(rdis[l], a[l]);
        return ;
    }
    build(l, Mid, lson); build(Mid + 1, r, rson);
    update(rt);
}
void modify(int l, int r, int x, int rt) {
    if(l == r) {
        tree[rt] = dis[l] + cal(rdis[l], a[l]);
        return ;
    }
    if(x <= Mid) modify(l, Mid, x, lson);
    else modify(Mid + 1, r, x, rson);
    update(rt);
}
signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> p;
    for(int i = 1; i <= m; i++) {
        int x, y, c, d;
        cin >> x >> y >> c >> d;
        ver[x].push_back({y, c});
        rver[y].push_back({x, d});
    }
    dijkstra(1, ver, dis);
    dijkstra(n, rver, rdis);
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 1);
    for(int i = 1; i <= p; i++) {
        int x, y;
        cin >> x >> y;
        a[x] = y;
        modify(1, n, x, 1);
        cout << tree[1] << endl;
    }
    return 0;
}