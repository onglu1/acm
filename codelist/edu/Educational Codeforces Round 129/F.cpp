//
// Created by onglu on 2022/5/23.
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
//const int N = 309;
int n, m, a[N], siz[N], ans = 0;
vector<pair<int, int> > ver[N];
vector<int> col[N];
map<int, int> nsiz[N], fa[N];
void init(int x, int pre) {
    siz[x] += 1;
    for(auto p : ver[x]) if(p.first != pre) {
        init(p.first, x);
        siz[x] += siz[p.first];
    }
}
void dfs(int x, int pre) {
    for(auto p : ver[x]) if(p.first != pre) {
        int c = p.second;
        int y = p.first;
        fa[x][c] = *col[c].rbegin();
        nsiz[fa[x][c]][c] -= siz[y];
        nsiz[y][c] = siz[y];
        col[c].push_back(y);
        dfs(y, x);
        col[c].pop_back();
    }
}
void cal(int x, int pre) {
    for(auto p : ver[x]) if(p.first != pre) {
        int c = p.second;
        int y = p.first;
        ans += nsiz[fa[x][c]][c] * nsiz[y][c];
        cal(y, x);
    }
}
void work() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        ver[x].push_back({y, z});
        ver[y].push_back({x, z});
    }
    init(1, 1);
    for(int i = 1; i <= n; i++) {
        nsiz[1][i] = siz[1];
        col[i].push_back(1);
    }
    dfs(1, 1);
    cal(1, 1);
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
//    cin >> Case;
    while(Case--) work();
    return 0;
}