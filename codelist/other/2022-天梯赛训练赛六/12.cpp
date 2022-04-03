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
#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N];
int vis[N], fa[N];
double z, r;
vector<int> ver[N];
double ans = 0;
void dfs(int x, double z) {
    ans += vis[x] * z;
    for(auto y : ver[x]) {
        dfs(y, z * (100 - r) * 0.01);
    }
}
void work() {
    cin >> n >> z >> r;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if(k == 0) cin >> vis[i];
        else {
            for(int j = 1; j <= k; j++) {
                int y;
                cin >> y;
                ver[i].push_back(y);
                fa[y] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++)
        if(!fa[i]){
            dfs(i, z);
        }
    printf("%lld\n", (int)ans);
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