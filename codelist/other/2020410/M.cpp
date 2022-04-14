#include <bits/stdc++.h>
using namespace std;
const int N = 309;
int n, m, s, t;
int g[N][N];
int vis[N], ans = 0;
vector<int> ver[N];
int match[N];
int dfs(int x) {
    for(auto i : ver[x]) {
        if(vis[i]) continue;
        vis[i] = 1;
        if(!match[i] || dfs(match[i])) {
            match[i] = x;
            return 1;
        }
    }
    return 0;
}
void work() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        memset(g[i], 0, sizeof(int) * (n + 10));
    }
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                g[i][j] |= g[i][k] & g[k][j];
            }
        }
    }
    for(int i = 1; i <= 2 * n; i++) ver[i].clear();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(g[i][j]) {
                ver[i].push_back(n + j);
                ver[n + j].push_back(i);
            }
        }
    }
    ans = 0;
    memset(match, 0, sizeof(int) * (2 * n + 10));
    for(int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(int) * (2 * n + 10));
        if(dfs(i)) ans++;
    }
    cout << n - ans << endl;
}
int main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    int Case;
    cin >> Case;
    while(Case--) work();
    return 0;
}