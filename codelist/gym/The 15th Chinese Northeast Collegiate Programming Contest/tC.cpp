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
#define int long long
using namespace std;
const int N = 3e5 + 1009;
const int mod = 998244353;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m;
int f[N][3], g[N][3];
vector<int> ver[N];
void dfs(int x, int pre) {
    f[x][0] = f[x][1] = 1; f[x][2] = 0;
    for(auto y : ver[x]) if(y != pre) {
        dfs(y, x);
        int g[3] = {f[x][0], f[x][1], f[x][2]};
        f[x][0] = (g[0] * ((f[y][0] + f[y][2]) % mod)) % mod;
        f[x][1] = (g[1] * f[y][0] % mod);
        f[x][2] = ((g[1] * ((f[y][1] + f[y][2]) % mod)) % mod + (g[2] * ((f[y][1] + f[y][2] + f[y][0]) % mod)) % mod) % mod;
    }

}
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) ver[i].clear();
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    dfs(1, 0);
    cout << (f[1][0] + f[1][2]) % mod << endl;
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