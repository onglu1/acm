//
// Created by onglu on 2022/4/2.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
#define int unsigned
using namespace std;
const int N = 3e5 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, q, a[N];
vector<vector<int> > g, tree;
void build(int l, int r, int rt, int rt2, int n) {
    if(l == r) {
        tree[rt2][rt] = g[n][l];
        return ;
    }
    build(l, Mid, lson, rt2, n);
    build(Mid + 1, r, rson, rt2, n);
    tree[rt2][rt] = min(tree[rt2][lson], tree[rt2][rson]);
}
int query(int l, int r, int L, int R, int rt, int rt2) {
    if(L <= l && r <= R) {
        return tree[rt2][rt];
    }
    int minn = -1;
    if(L <= Mid) minn = min(minn, query(l, Mid, L, R, lson, rt2));
    if(Mid <  R) minn = min(minn, query(Mid + 1, r, L, R, rson, rt2));
    return minn;
}
void merge(int l, int r, int rt, vector<int> &t1, vector<int> &t2, vector<int> &tar) {
    if(l == r) {
        tar[rt] = min(t1[rt], t2[rt]);
        return ;
    }
    merge(l, Mid, lson, t1, t2, tar);
    merge(Mid + 1, r, rson, t1, t2, tar);
    tar[rt] = min(tar[lson], tar[rson]);
}
void buildR(int l, int r, int rt) {
    if(l == r) {
        build(1, m, 1, rt, l);
        return ;
    }
    buildR(l, Mid, lson);
    buildR(Mid + 1, r, rson);
    merge(1, m, 1, tree[lson], tree[rson], tree[rt]);
}
int queryR(int l, int r, int L1, int R1, int L2, int R2, int rt) {
    if(L1 <= l && r <= R1) {
        return query(1, m, L2, R2, 1, rt);
    }
    int minn = -1;
    if(L1 <= Mid) minn = min(minn, queryR(l, Mid, L1, R1, L2, R2, lson));
    if(Mid <  R1) minn = min(minn, queryR(Mid + 1, r, L1, R1, L2, R2, rson));
    return minn;
}
void work() {
    g.clear(); tree.clear();
    for(int i = 0; i <= n; i++) g.push_back(vector<int> (m + 1));
    for(int i = 0; i <= n * 4 + 1; i++) tree.push_back(vector<int> (m * 4 + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    buildR(1, n, 1);
    for(int i = 1; i <= q; i++) {
        int L1, R1, L2, R2;
        cin >> L1 >> L2 >> R1 >> R2;
        L1 += 1; L2 += 1;
        R1 += 1; R2 += 1;
        cout << queryR(1, n, L1, R1, L2, R2, 1) << endl;
    }
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n >> m >> q) {
        if(n + m + q == 0) break;
        work();
    }
    return 0;
}