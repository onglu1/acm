//
// Created by onglu on 2022/6/25.
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
int n, m;
struct data {
    int pos, val;
};
struct node {
    int ls, rs, v;
    node() {}
    node(int ls, int rs, int v) : ls(ls), rs(rs), v(v) {}
} tree[N];
void update(int rt) {
    tree[rt].v = tree[tree[rt].ls].v + tree[tree[rt].rs].v;
}
vector<data> v;
vector<int> root;
void work() {
    cin >> n;
    v = vector<int>(n);
    root = vector<node>(n);
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v[i - 1] = {i, x};
    }
    std::sort(v.begin(), v.end(), [](const data &a, const data &b) {
        return a.val < b.val;
    });
    for(int i = 0; i < n; i++) {

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
    // cin >> Case;
    while(Case--) work();
    return 0;
}
/*
变成求区间mex，和统计小于mex的数字个数
直接上主席树就行
*/