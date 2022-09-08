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
const int N = 3e5 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
struct task {
    int l, r, id;
};
struct node {
    int id, pos, flag, mex;
};
vector<int> ans;
int n, m;
map<int, int> pos;
vector<node> b;
vector<int> a;
vector<task> tsk;
int tree[N * 4];
void update(int rt) {
    tree[rt] = min(tree[lson], tree[rson]);
}
void build(int l, int r, int rt) {
    if(l == r) return (void)(tree[rt] = -1);
    build(l, Mid, lson); build(Mid + 1, r, rson);
    update(rt);
}
void modify(int l, int r, int pos, int val, int rt) {
    if(l == r) return (void) (tree[rt] = val);
    if(pos <= Mid) modify(l, Mid, pos, val, lson);
    else modify(Mid + 1, r, pos, val, rson);
    update(rt);
}
int queryMex(int l, int r, int L, int R, int rt) {
    if(l == r) return (tree[rt] < L ? -1 : l + 1);
    if(tree[rt] >= L) return r + 1;
    if(tree[lson] >= L) return max(Mid + 1, queryMex(Mid + 1, r, L, R, rson));
    else return queryMex(l, Mid, L, R, lson);
}
int queryMex(int l, int r) {
    return queryMex(1, n, l, r, 1);
}
void modify(int pos, int val) {
    modify(1, n, pos, val, 1);
}

vector<int> tree1;
void addT(int x, int y) {
    for(; x <= n; x += x & -x)
        tree1[x] += y;
}
int queryT(int x) {
    int ans = 0;
    for( ; x; x -= x & -x)
        ans += tree1[x];
    return ans;
}
void work() {
    cin >> n;
    a = vector<int>(n + 100);
    tree1 = vector<int>(n + 100);
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    ans = vector<int>(m + 100);
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        tsk.push_back({x, y, i});
        ans[i] = y - x + 1;
    }
    std::sort(tsk.begin(), tsk.end(), [](const task &a, const task &b) {
        if(a.r != b.r) return a.r < b.r;
        else return a.l < b.l;
    });
    int now = 0;
    for(auto x : tsk) {
        int l = x.l, r = x.r;
        while(now < r) {
            now += 1;
            if(a[now] > n) continue;
            pos[a[now]] = now;
            modify(a[now], now);
        }
        int mex = queryMex(l, r);
        if(mex != -1) {
            b.push_back({x.id, x.l - 1, -1, mex});
            b.push_back({x.id, x.r, 1, mex});
        }
    }
    std::sort(b.begin(), b.end(), [](const node &a, const node &b) {
        return a.pos < b.pos;
    });
    now = 0;
    for(auto x : b) {
        while(now < x.pos) {
            now += 1;
            if(a[now] > n) continue;
            addT(a[now], 1);
        }
        ans[x.id] -= x.flag * queryT(x.mex - 1);
    }
    for(int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
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
维护每个数的最小出现时间，然后每次在线段树上得到mex
线段树统计区间最小值
最后统计l，r内比mex小的，可以直接二次离线做，先求mex，再去搞
*/