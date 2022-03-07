#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 4009;
int n, m, f[2009][2009], siz[N];
int g[2009];
int head[N], nxt[N], ver[N], edge[N], tot;
void add(int x, int y, int w) {
    nxt[++tot] = head[x]; head[x] = tot; ver[tot] = y; edge[tot] = w;
}

void dfs(int x, int pre) {
    siz[x] = 1;

    for(int i = head[x]; i; i = nxt[i]) if(ver[i] != pre) {
        int y = ver[i];
        dfs(y, x);
        memcpy(g, f[x], sizeof(int) * (min(m, siz[x]) + 5));
        for(int j = max(siz[x] - (n - m), 0ll); j <= min(m, siz[x]); j++) {
            for(int k = max(siz[y] - (n - m), 0ll); k <= min(siz[y], m - j); k++) {
                //f[i][j]子树i中，选择j个黑点的最大价值
                f[x][j + k] = max(f[x][j + k], g[j] + f[y][k] + edge[i] * (k * (m - k) + (siz[y] - k) * (n - m - (siz[y] - k))));
            }
        }
        siz[x] += siz[y];
    }
}

signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        add(x, y, w);
        add(y, x, w);
    }
    dfs(1, 0);
    cout << f[1][m] << endl;
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}