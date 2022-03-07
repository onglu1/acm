//
// Created by onglu on 2022/2/26.
//

#include <bits/stdc++.h>

#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
const int inf = 0x3f3f3f3f;
int n, m, a[N], s, t;
int d[N], id[N], L[N], R[N];
queue<int> q;
int head[N], nxt[N], ver[N], edge[N], tot = 1;
void add(int x, int y, int w) {
    nxt[++tot] = head[x]; head[x] = tot; ver[tot] = y; edge[tot] = w;
}
int bfs() {
    memset(d, 0, sizeof(int) * (t + 10)); d[s] = 1;
    while(q.size()) q.pop(); q.push(s);
    while(q.size()) {
        int x = q.front(); q.pop();
        for(int i = head[x]; i; i = nxt[i]) {
            if(d[ver[i]] || edge[i] <= 0) continue;
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
        k = dinic(ver[i], min(edge[i], res));
        if(k == 0) d[ver[i]] = 0;
        edge[i] -= k;
        res -= k;
        edge[i ^ 1] += k;
    }
    return flow - res;
}
void work() {
    int a, b;
    cin >> n >> m >> a >> b;
    s = n + 1; t = n + 2;
    for(int i = 1; i <= m; i++) {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        add(x, y, r - l);add(y, x, 0);
        id[i] = tot; L[i] = l;
        add(s, y, l); add(y, s, 0);
        add(x, t, l); add(t, x, 0);
    }
    add(b, a, inf); add(a, b, 0);
    int ans = 0;
    while(bfs())
        ans += dinic(s, inf);
    for(int i = head[s]; i; i = nxt[i]) {
        if(edge[i] > 0) {
            cout << "No Solution" << endl;
            return ;
        }
    }
    cout << ans << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
    while (Case--) work();
    return 0;
}