#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e5 + 1009;
const int inf = 0x3f3f3f3f;
int n, m, s, t;
int d[N];
int head[N], nxt[N], ver[N], edge[N], tot = 1;
vector<int> v;
int add(int x, int y, int w) {
    ver[++tot] = y; nxt[tot] = head[x]; head[x] = tot; edge[tot] = w;
    return tot;
}
queue<int> q;
int bfs() {
    memset(d, 0, sizeof(int) * (t + 10)); d[s] = 1;
    while(q.size()) q.pop(); q.push(s);
    while(q.size()) {
        int x = q.front(); q.pop();
        for(int i = head[x]; i; i = nxt[i]) {
            if(d[ver[i]]) continue;
            if(edge[i] <= 0) continue;
            d[ver[i]] = d[x] + 1;
            q.push(ver[i]);
        }
    }
    return d[t];
}
int dinic(int x, int flow) {
    if(x == t) return flow;
    int k, res = flow;
    for(int i = head[x]; i && res; i = nxt[i]) {
        if(d[ver[i]] != d[x] + 1 || edge[i] <= 0) continue;
        k = dinic(ver[i], min(res, edge[i]));
        if(k == 0) d[ver[i]] = 0;
        edge[i] -= k;
        edge[i ^ 1] += k;
        res -= k;
    };
    return flow - res;
}
void work() {
    cin >> n >> m;
    v.clear();
    s = 2 * n + m + 1;
    t = 2 * n + m + 2;
    tot = 1;
    memset(head, 0, sizeof(int) * (2 * n + m + 1009));
    for(int i = 1; i <= n; i++) {
        int w;
        cin >> w;
        add(i, i + n, w);
        add(i + n, i, 0);
        add(i + n, t, inf);
        add(t, i + n, 0);
    }
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        int a;
        add(i + 2 * n, x, 1);
        add(x, i + 2 * n, 0);
        a = add(i + 2 * n, y, 1);
        add(y, i + 2 * n, 0);
        v.push_back(a);
        add(s, i + 2 * n, 1);
        add(i + 2 * n, s, 0);
    }
    int maxflow = 0;
    while(bfs())
        maxflow += dinic(s, inf);
    cout << m - maxflow << endl;
    for(auto x : v) {
        cout << (edge[x] != 0);
    }
    cout << endl;
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
/*
 * 最好每个点都不超过它自己的度数
 *
 */
