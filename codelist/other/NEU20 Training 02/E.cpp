#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int n, m, ans, now, f;
map<int, int> g[100009];
void dfs(int x) {
    if(f) return ;
    if(now == n + 1) {
        cout << ans << endl;
        f = 1;
        return ;
    }
    if(x == 1) {
        while(!f) {
            if(g[x][now + 1] != 1) {
                g[x][now + 1] = 1;
                ans++;
            }
            now++;
            dfs(now);
        }
    } else {
        while(!f) {
            if(g[x][now + 1] == 1) {
                now++;
                dfs(now);
            } else return ;
        }
    }
}
void work() {
    cin >> n >> m;
    ans = 0; f = 0;
    for(int i = 1; i <= n; i++) g[i].clear();
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x][y] = g[y][x] = 1;
    }
    now = 1;
    dfs(1);
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
 * 建出每个点开始最多能访问到的最右位置
 * 然后从第一个点开始搜，如果下一个点超出
 *
 */