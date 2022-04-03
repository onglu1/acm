#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 2e6 + 1009;
struct Edge {
    int to, w;
};
int n, m, c, a[N], siz[N], mson[N], wmson[N];
int cnt[N], col[N], sum, Son, ans[N];
vector<Edge> son[N];

void dfs1(int x, int pre) {
    siz[x] = 1;
    mson[x] = 0;
    for(auto y : son[x]) if(y.to != pre) {
            dfs1(y.to, x);
            siz[x] += siz[y.to];
            if(!mson[x] || siz[y.to] > siz[mson[x]]) {
                wmson[x] = y.w;
                mson[x] = y.to;
            }
        }
}
void add(int x, int pre, int v) {
    for(auto y : son[x]) {
        if(y.to == pre || y.to == Son) continue;
        sum -= cnt[y.w];// * y.w * cnt[y.w] * y.w;
        cnt[y.w] += v;
        sum += cnt[y.w];// * y.w * cnt[y.w] * y.w;
        add(y.to, x, v);
    }
}
void dfs2(int x, int pre, int keep) {
    for(auto y : son[x]) {
        if(y.to == pre || y.to == mson[x]) continue;
        dfs2(y.to, x, 0);
    }
    if(mson[x]) {
        dfs2(mson[x], x, 1), Son = mson[x];
        sum -= cnt[wmson[x]];// * wmson[x] * cnt[wmson[x]] * wmson[x];
        cnt[wmson[x]] += 1;
        sum += cnt[wmson[x]];// * wmson[x] * cnt[wmson[x]] * wmson[x];
    }
    add(x, pre, 1); Son = 0;
    ans[x] = sum;
    if(!keep) add(x, pre, -1), sum = 0;
}
void work() {
    cin >> n >> m >> c;
    for(int i = 1; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        son[x].push_back({y, w});
        son[y].push_back({x, w});
    }
    dfs1(1, 0);
    dfs2(1, 0, 1);
    while(m--) {
        int t;
        cin >> t;
        cout << ans[t] << endl;
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
//    cin >> Case;
    while (Case--) work();
    return 0;
}
/*
11 6 10
1 2 9
2 3 1
3 4 6
2 5 7
4 6 5
5 7 7
7 8 8
7 9 3
7 10 6
3 11 3
5
7
10
6
1
5
 */