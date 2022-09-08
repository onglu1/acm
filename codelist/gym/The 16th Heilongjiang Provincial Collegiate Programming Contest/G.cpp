//
// Created by onglu on 2022/5/11.
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
const int N = 2001 * 2001 * 4;
const int dx[] = {0, -1};
const int dy[] = {-1, 0};
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, cnt[2001 * 2001];
char g[2001][2001];
int head[2001 * 2001], nxt[N], ver[N], tot = 1;
void add(int x, int y) {
    ver[++tot] = y; nxt[tot] = head[x]; head[x] = tot;
}
int root;
int dfn[2001 * 2001], low[2001 * 2001], dfntot;
void tarjan(int x, int ff) {
//    if(x == root) cout << x << endl;
    dfn[x] = low[x] = ++dfntot;
    int nohigher = 1;
    for(int i = head[x]; i; i = nxt[i]) {
        int y = ver[i];
        if(!dfn[y]) {
            tarjan(y, dfn[x]);
            low[x] = min(low[x], low[y]);
            if(low[y] >= dfn[x]) {
                cnt[x] += 1;
            }
        } else {
            low[x] = min(low[x], dfn[y]);
            if(dfn[y] < ff) nohigher = 0;
        }
    }
//    if(x == 7) cout << nohigher << endl;
//    cout << x << " " << nohigher << endl;
    if(nohigher && root != x) cnt[x] += 1;
}
int block;
void get_cut() {
    for(int i = 1; i <= n * m; i++)
        if(g[(i - 1) / m + 1][(i - 1) % m + 1] == '.' && !dfn[i]) {
            block += 1;
            tarjan(root = i, -1);
        }
}
void work() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(g[i][j] == '.') {
                for(int k = 0; k < 2; k++) {
                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    if(xx <= 0 || yy <= 0 || xx > n || yy > m) continue;
                    if(g[xx][yy] == '.') {
                        add((i - 1) * m + j, (xx - 1) * m + yy);
                        add((xx - 1) * m + yy, (i - 1) * m + j);
                    }
                }
            }
        }
    }
    get_cut();
    int ans = 0;
    for(int i = 1; i <= n * m; i++) {
        ans = max(ans, cnt[i]);
    }
    cout << block + ans - 1 << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
//    cin >> Case;
    while (Case--) work();
    return 0;
}