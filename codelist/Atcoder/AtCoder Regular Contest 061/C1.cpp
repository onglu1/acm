#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e6 + 1009;
struct Edge{
    int to, c;
};
int n, m, pre[N], dis[N];
vector<pair<int, int> > v[N];
vector<Edge> ver[N];
void add(int x, int y, int p) {
    ver[x].push_back({y, p});
}
void build(int p) {
    for(auto e : v[p]) {
        int x = e.first;
        int y = e.second;
        pre[x] = -1;
        pre[y] = -1;
    }
    for(auto e : v[p]) {
        int x = e.first;
        int y = e.second;
        if(pre[x] == -1) {
            pre[x] = ++n;
            add(n, x, 1);
            add(x, n, 1);
        }
        if(pre[y] == -1) {
            pre[y] = ++n;
            add(n, y, 1);
            add(y, n, 1);
        }
        add(pre[x], pre[y], 0);
        add(pre[y], pre[x], 0);
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int s = 1, t = n;
    for(int i = 1; i <= m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        v[c].push_back({x, y});
    }
    for(int i = 1; i < N; i++) {
        build(i);
    }
    deque<int> q;
    memset(dis, -1, sizeof(dis)); dis[s] = 0;
    q.push_back(s);
    while(q.size()) {
        int x = q.front(); q.pop_front();
        for(auto e : ver[x]) {
            int y = e.to, c = e.c;
            if(dis[y] != -1) continue;
            dis[y] = dis[x] + c;
            if(c == 1) {
                q.push_back(y);
            } else {
                q.push_front(y);
            }
        }
    }
    if(dis[t] == -1) cout << -1 << endl;
    else cout << dis[t] / 2 << endl;
    return 0;
}