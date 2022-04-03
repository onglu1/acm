//
// Created by onglu on 2022/3/24.
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
//const int N = 309
int n, m, a[N], f[N];
vector<int> ver[N];
void dfs(int x, int pre, int d) {
    if(d & 1) f[x] = -f[x];
    for(auto y : ver[x]) if(y != pre) {
        dfs(y, x, d + 1);
    }
}
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        ver[i].clear();
    }
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    for(int i = 1; i <= n; i++) {
        f[i] = ver[i].size();
    }
    dfs(1, 1, 1);
    for(int i = 1; i <= n; i++) {
        cout << f[i] << " \n"[i == n] ;
    }
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
    cin >> Case;
    while (Case--) work();
    return 0;
}