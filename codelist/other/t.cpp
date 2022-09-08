#include <bits/stdc++.h>
using namespace std;
int n, m, g[109][109];
signed main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof(g));
    for(int i = 1; i <= n; i++) g[i][i] = 0;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x][y] = g[y][x] = min(g[x][y], 1);
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    int ans = 0;
    int x;
    cin >> x;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, g[x][i]);
    }
    cout << 2 * ans << endl;
    return 0;
}
/*
5 7
2 1
1 4
2 4
2 3
3 4
3 5
4 5
*/