//
// Created by onglu on 2022/4/27.
//

#include <bits/stdc++.h>
#define int long long
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
int n, m, col[N];
int siz[N], son[N];
vector<int> ver[N];
void build(int x, int pre) {
    siz[x] = 1; son[x] = 0;
    for(auto y : ver[x]) if(y != pre) {
        build(y, x);
        if(siz[y] > siz[son[x]]) son[x] = y;
        siz[x] += siz[y];
    }
}
int cnt[N], maxn;
int cntcnt[N], ans[N];
void sub(int x) {
    cntcnt[cnt[x]] -= x;
    cnt[x] -= 1;
    cntcnt[cnt[x]] += x;
    while(maxn > 0 && cntcnt[maxn] == 0) maxn -= 1;
}
void add(int x) {
    cntcnt[cnt[x]] -= x;
    cnt[x] += 1;
    cntcnt[cnt[x]] += x;
    maxn = max(maxn, cnt[x]);
}
void travel(int x, int pre, void (*opt)(int x)) {
    opt(col[x]);
    for(auto y : ver[x]) if(y != pre) {
        travel(y, x, opt);
    }
}
void dfs(int x, int pre, int f) {
    for(auto y : ver[x]) if(y != pre && y != son[x]) {
        dfs(y, x, 0);
    }
    if(son[x]) dfs(son[x], x, 1);
    for(auto y : ver[x]) if(y != pre && y != son[x]) {
        travel(y, x, add);
    }
    add(col[x]);
    ans[x] = cntcnt[maxn];
    if(!f) travel(x, pre, sub);
}
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> col[i];
    }
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    build(1, 0);
    dfs(1, 0, 1);
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
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
    while (Case--) work();
    return 0;
}