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
int dis[N], vis[N], pre[N], flow[N], S;
int maxflow, minncost;
queue<int> q;
int SPFA() {
    queue<int> q; q.push(s);
    memset(dis, 0x3f, sizeof(int) * (t + 10)); dis[s] = 0;
    memset(vis, 0, sizeof(int) * (t + 10)); vis[s] = 1;
    q.push(s); flow[s] = 0x3f3f3f3f;
    while(q.size()) {
        int x = q.front();
        vis[x] = 0; q.pop();
        for(int i = head[x]; i; i = nxt[i]) {
            if(edge[i] <= 0) continue;
            if(dis[ver[i]] > dis[x] + cost[i]) {
                dis[ver[i]] = dis[x] + cost[i];
                pre[ver[i]] = i;
                flow[ver[i]] = min(flow[x], edge[i]);
                if(!vis[ver[i]]) {
                    q.push(ver[i]);
                    vis[ver[i]] = 1;
                }
            }
        }
    }
    return dis[t] != 0x3f3f3f3f;
}
void update() {
    int x = t;
    while(x != s) {
        int i = pre[x];
        edge[i] -= flow[t];
        edge[i ^ 1] += flow[t];
        x = ver[i ^ 1];
    }
    maxflow += flow[t];
    minncost += dis[t] * flow[t];
}
void work() {
    cin >> n >> m >> mod;
    tot = 1; minncost = 0; maxflow = 0;
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
        update();
    }
    cout << -minncost << endl;
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