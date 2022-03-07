#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 1009;
int n, m, g[N][N], finish[N][N];
struct node {
    int x, y, c;
};
int cmp(int x, int y) {
    if(x == 0  || y == 0) return 1;
    else return x == y;
}
queue<pair<int, int> > q;
vector<node> ans;
int check(int x, int y) {
    if(finish[x][y]) return 0;
    int col = 0;
    for(int i = 0; i <= 1; i++) {
        for(int j = 0; j <= 1; j++) {
            if(g[x + i][y + j] != 0) {
                if(col != 0 && g[x + i][y + j] != col) {
                    return 0;
                }
                col = g[x + i][y + j];
            }
        }
    }
    if(col == 0) finish[x][y] = 1;
    return col;
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
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    while(q.size()) q.pop();
    for(int i = 1; i + 1 <= n; i++) {
        for(int j = 1; j + 1 <= m; j++) {
            int t = check(i, j);
            if(t) {
                q.push({i, j});
                ans.push_back({i, j, t});
                g[i][j] = 0;
                g[i][j + 1] = 0;
                g[i + 1][j] = 0;
                g[i + 1][j + 1] = 0;
            }
        }
    }
    while(q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int xx = max(1, x - 1); xx + 1 <= n && xx <= x + 1; xx++) {
            for(int yy = max(1, y - 1); yy + 1 <= m && yy <= y + 1; yy++) {
                int t = check(xx, yy);
                if(t) {
                    q.push({xx, yy});
                    ans.push_back({xx, yy, t});
                    g[xx][yy] = 0;
                    g[xx][yy + 1] = 0;
                    g[xx + 1][yy] = 0;
                    g[xx + 1][yy + 1] = 0;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(g[i][j] != 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto x : ans) {
        cout << x.x << " " << x.y << " " << x.c << endl;
    }
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}