#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e6 + 1009;
int n;
map<int, int> g;
int dfs(int x) {
    if(g.count(x)) return g[x];
    if(x == 0) return 1;
    g[x] = (dfs(x >> 1) + dfs((x - 1) >> 1)) % mod;
    if(x > 1) g[x] = (g[x] + dfs((x - 2) >> 1)) % mod;
    return g[x];
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
    cout << dfs(n) << endl;
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}
/*
 * v跟u奇偶性相同，并且((v-u)/2) & u=0
 */