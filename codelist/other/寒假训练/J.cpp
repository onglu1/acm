#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e3 + 1009;
int n, hp[N], siz[N], f[2][N][N];
int g[2][N];
vector<int> son[N];
void dfs(int x) {
    siz[x] = 1;
    memset(f[0][x], 0x3f, sizeof(int) * (n + 10));
    memset(f[1][x], 0x3f, sizeof(int) * (n + 10));
    f[0][x][0] = hp[x];
    f[1][x][1] = 0;
    for(auto y : son[x]) {
        dfs(y);
        memcpy(g[0], f[0][x], sizeof(int) * (siz[x] + 1));
        memcpy(g[1], f[1][x], sizeof(int) * (siz[x] + 1));
        memset(f[0][x], 0x3f, sizeof(int) * (siz[x] + 1));
        memset(f[1][x], 0x3f, sizeof(int) * (siz[x] + 1));
        for(int i = 0; i <= siz[x]; i++) {
            for(int j = 0; j <= siz[y]; j++) {
                if(i >= 1)
                    f[1][x][i + j] = min(f[1][x][i + j], g[1][i] + min(f[0][y][j], f[1][y][j]));
                f[0][x][i + j] = min(f[0][x][i + j], g[0][i] + min(f[0][y][j] + hp[y], f[1][y][j]));
            }
        }
        siz[x] += siz[y];
    }
}
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        son[i].clear();
    }
    for(int i = 2; i <= n; i++) {
        int fa;
        cin >> fa;
        son[fa].push_back(i);
    }
    for(int i = 1; i <= n; i++) cin >> hp[i];
    dfs(1);
    for(int i = 0; i <= n; i++) {
        cout << min(f[0][1][i], f[1][1][i]) <<  " ";
    }
    cout << "\n";
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
f[0][x][k]表示以x为根的子树，根节点不删，一共删k个点，方案数
f[1][x][k]表示以x为根的子树，根节点删，一共删k个点，方案数
f[1][x][k] = min(f[0][a][i], f[1][a][i]) + min(f[0][b][j], f[1][b][j])
f[0][x][k] = min(f[0][a][i] + hp[a], f[1][a][i]) + min(f[0][b][j] + hp[b], f[1][b][j])
 */