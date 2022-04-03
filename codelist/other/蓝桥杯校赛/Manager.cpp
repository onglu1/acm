//
// Created by onglu on 2022/3/27.
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
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, a[N], siz[N], dfn[N], tot = 0;
vector<int> ver[N];
void dfs(int x, int pre) {
    siz[x] = 1; dfn[x] = ++tot;
    for(auto y : ver[x]) if(y != pre) {
        dfs(y, x);
        siz[x] += siz[y];
    }
}
int check(int x, int y) {
    int l = dfn[x];
    int r = dfn[x] + siz[x] - 1;
    if(l <= dfn[y] && dfn[y] <= r) {
        return 1;
    }
    return 0;
}
void work() {
    tot = 0;
    for(int i = 1; i <= n; i++) ver[i].clear();
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    dfs(1, 0);
    int cnt =0 ;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        if(check(x, y) || check(y, x)) {
            cnt++;
        }
    }
    cout << cnt << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n >> m) work();
    return 0;
}