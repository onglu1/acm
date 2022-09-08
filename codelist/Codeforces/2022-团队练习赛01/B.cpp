//
// Created by onglu on 2022/5/7.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2e4 + 1009;
const int M = 4e5 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m;
int v[3][N], mod, s, t;
int head[N], nxt[M], edge[M], cost[M], ver[M], tot = 1;
void add(int x, int y, int w, int c) {
    ver[++tot] = y; nxt[tot] = head[x]; head[x] = tot; cost[tot] = c; edge[tot] = w;
}
const int inf = 0x3f3f3f3f;
int d[N], vis[N], S;
int mincost;
queue<int> q;
int SPFA() {
    while(q.size()) q.pop(); q.push(s);
    memset(d, 0x3f, sizeof(int) * (t + 10)); d[s] = 0;
    memset(vis, 0, sizeof(int) * (t + 10)); vis[s] = 1;
    while(q.size()) {
        int x = q.front(); q.pop();
        vis[x] = 0;
        for(int i = head[x]; i; i = nxt[i]) {
            if(edge[i] <= 0) continue;
            if(d[ver[i]] > d[x] + cost[i]) {
                d[ver[i]] = d[x] + cost[i];
                if(!vis[ver[i]]) {
                    vis[ver[i]] = 1;
                    q.push(ver[i]);
                }
            }
        }
    }
    return d[t] != 0x3f3f3f3f;
}
int dinic(int x, int flow) {
    if(x == t) return flow;
    vis[x] = 1;
    int k, res = flow;
    for(int i = head[x]; i && res; i = nxt[i]) {
        if(vis[ver[i]]) continue;
        if(d[ver[i]] != d[x] + cost[i] || edge[i] <= 0) continue;
        k = dinic(ver[i], min(edge[i], res));
        if(!k) d[ver[i]] = -1;
        edge[i] -= k;
        edge[i ^ 1] += 1;
        res -= k;
        mincost += cost[i] * k;
    }
    vis[x] = 0;
    return flow - res;
}
void work() {
    cin >> n >> m >> mod;
    tot = 1; mincost = 0;
    s = 6 * n + 1; t = 6 * n + 2;
    S = 6 * n + 3;
    memset(head, 0, sizeof(int) * (n * 6 + 10));
    for(int i = 1; i <= n; i++) cin >> v[1][i];
    for(int i = 1; i <= n; i++) cin >> v[0][i];
    for(int i = 1; i <= n; i++) cin >> v[2][i];
    add(s, S, m, 0);
    add(S, s, 0, 0);
    for(int i = 1; i <= n; i++) {
        add(S, i, 1, 0);
        add(i, S, 0, 0);
        add(5 * n + i, t, 1, 0);
        add(t, 5 * n + i, 0, 0);
    }
    for(int c = 0; c < 3; c++) {
        for(int i = 1; i <= n; i++) {
            add(c * 2 * n + i, (c * 2 + 1) * n + i, 1, 0);
            add((c * 2 + 1) * n + i, c * 2 * n + i, 0, 0);
        }
    }
    for(int i = 1; i <= n; i++) {
        int b1 = n;
        int b2 = 2 * n;
        for(int j = 1; j <= n; j++) {
            int c = (1ll * (v[0][i] + v[1][j]) * (v[0][i] ^ v[1][j]) % mod);
            add(b1 + i, b2 + j, 1, -c);
            add(b2 + j, b1 + i, 0,  c);
        }
    }
    for(int i = 1; i <= n; i++) {
        int b1 = 3 * n;
        int b2 = 4 * n;
        for(int j = 1; j <= n; j++) {
            int c = (1ll * (v[1][i] + v[2][j]) * (v[1][i] ^ v[2][j]) % mod);
            add(b1 + i, b2 + j, 1, -c);
            add(b2 + j, b1 + i, 0,  c);
        }
    }
    int maxflow = 0;
    while(SPFA()) {
        maxflow += dinic(s, inf);
    }
    cout << -mincost << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
    cin >> Case;
    while (Case--) work();
    return 0;
}