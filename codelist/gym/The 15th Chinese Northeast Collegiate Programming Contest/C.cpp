//
// Created by onglu on 2022/5/18.
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
int n, m, a[N], vis[N];
vector<int> ver[N];
int tt;
int dfs(int x, int pre) {
    tt += 1;
    for(auto y : ver[x]) if(y != pre && vis[y]) {
        dfs(y, x);
    }
}
int check() {
    for(int i = 1; i <= n; i++) if(vis[i]) {
        tt = 0;
        dfs(i, i);
        if(tt == 1) {
            return false;
        }
    }
    return true;

}
void work() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    int ans = 0;
    for(int i = 0; i < 1 << n; i++) {
        for(int j = 0; j < n; j++) {
            vis[j + 1] = i >> j & 1;
        }
        ans += check();
    }
    cout << ans << endl;
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
    while(Case--) work();
    return 0;
}