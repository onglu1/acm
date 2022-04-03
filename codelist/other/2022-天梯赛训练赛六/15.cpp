//
// Created by onglu on 2022/3/23.
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
const int N = 50;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N], vis[N];
int g[N][N];
vector<int> path;
void dfs(int d) {
    if(d == n) {
        for(int i = 0; i < path.size(); i++) {
            cout << path[i] << " \n"[i == path.size() - 1];
        }
        exit(0);
    }
    int ok = 0;
    for(int i = 1; i <= n; i++) if(!vis[i])
        if(g[i][1] == 1 || g[1][i] == 2)
            ok = 1;
    if(!ok) return ;
    for(int i = 1; i <= n; i++) if(!vis[i] && (g[*path.rbegin()][i] == 1 || g[i][*path.rbegin()] == 2)) {
        vis[i] = 1;
        path.push_back(i);
        dfs(d + 1);
        vis[i] = 0;
        path.pop_back();
    }
}
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            if(c == 'W') g[i][j] = 1;
            else if(c == 'L') g[i][j] = 2;
            else g[i][j] = 0;
        }
    }
    vis[1] = 1;
    path.push_back(1);
    dfs(1);
    cout << "No Solution" << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
//  cin >> Case;
    while (Case--) work();
    return 0;
}