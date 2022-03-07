#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 1009;
int n, m, a[N][N], p[N], vis[N];

int ans = -0x3f3f3f3f;
void dfs(int x, int now) {
    if(x > n) {
        ans = max(ans, now);
    }
    if(vis[x]) {
        dfs(x + 1, now);
    } else {
        vis[x] = 1;
        for(int i = x + 1; i <= n; i++) if(!vis[i]) {
            vis[i] = 1;
            dfs(x + 1, now ^ a[x][i]);
            vis[i] = 0;
        }
        vis[x] = 0;
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
    cin >> n;
    n *= 2;
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }
    dfs(1, 0);
    cout << ans << endl;
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}