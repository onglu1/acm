//
// Created by onglu on 2022/2/26.
//

#include <bits/stdc++.h>

#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
//const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
const int inf = 0x3f3f3f3f;
const int N = 429;
const int M = 5e5 + 1009;
int n, m, ispa[N][N], sr, st;
int g[N][N];
char s[M];
vector<string> v;
void Insert(int l, int r) {
    string now = "";
    for(int i = l; i <= r; i++) now = now + s[i];
    for(auto x : v) {
        if(x == now)
            return ;
    }
    v.push_back(now);
}
int head[M], ver[M], nxt[M], edge[M], tot = 1;
void add(int x, int y, int w) {
    ver[++tot] = y; nxt[tot] = head[x]; head[x] = tot; edge[tot] = w;
}
int d[M];
queue<int> q;
int bfs() {
    memset(d, 0, sizeof(int) * (st + 10)); d[sr] = 1;
    while(q.size()) q.pop(); q.push(sr);
    while(q.size()) {
        int x = q.front(); q.pop();
        for(int i = head[x]; i; i = nxt[i]) {
            if(d[ver[i]]) continue;
            if(edge[i] <= 0) continue;
            d[ver[i]] = d[x] + 1;
            q.push(ver[i]);
        }
    }
    return d[st];
}
int dinic(int x, int flow) {
    if(x == st) return flow;
    int k, res = flow;
    for(int i = head[x]; i && res; i = nxt[i]) {
        if(d[ver[i]] != d[x] + 1 || edge[i] <= 0) continue;
        k = dinic(ver[i], min(res, edge[i]));
        if(k == 0) d[ver[i]] = 0;
        edge[i] -= k;
        edge[i ^ 1] += k;
        res -= k;
    }
    return flow - res;
}
void work() {
    cin >> (s + 1);
    n = strlen(s + 1);
    for(int i = 1; i <= n; i++) {
        ispa[i][i] = 1;
        ispa[i][i - 1] = 1;
    }
    for(int len = 2; len <= n; len++) {
        for(int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            ispa[i][j] = (s[i] == s[j]) && (ispa[i + 1][j - 1]);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) if(ispa[i][j]) {
            Insert(i, j);
        }
    }
    for(int i = 1; i <= v.size(); i++) {
        for(int j = 1; j <= v.size(); j++) if(i != j) {
            if(v[i - 1].find(v[j - 1]) != v[i - 1].npos) {
                g[i][j] = 1;
            }
        }
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                g[i][j] |= g[i][k] && g[k][j];
            }
        }
    }
    sr = 2 * n + 1; st = 2 * n + 2;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) if(i != j && g[i][j]) {
                add(i, j + n, 1);
                add(j + n, i, 0);

        }
    }
    for(int i = 1; i <= v.size(); i++) {
        add(sr, i, 1);
        add(i, sr, 0);
        add(i + n, st, 1);
        add(st, i + n, 0);
    }
    int maxflow = 0;
    while(bfs()) {
        maxflow += dinic(sr, inf);
    }
    cout << v.size() - maxflow << endl;
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