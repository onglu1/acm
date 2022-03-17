//
// Created by onglu on 2022/3/16.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define son(x, f) tree[x].ch[f]
#define val(x) tree[x].val
#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, tot;
map<int, int> pos, dth, fa;
struct node {
    int val;
    int ch[2];
} tree[N];
int newNode(int x) {
    val(++tot) = x;
    son(tot, 0) = son(tot, 1) = -1;
    return tot;
}
void Insert(int x, int rt, int d) {
    int f = x > val(rt);
    if(son(x, f) == -1) {
        int t = newNode(x);
        son(x, f) = t;
        pos[x] = t;
        dth[x] = d;
        fa[x] = val(rt);
    } else {
        Insert(x, son(x, f), d + 1);
    }
}
int root = -1;
int isroot(int x) {
    if(!pos.count(x)) return false;
    return root == pos[x];
}
int issiblings(int x, int y) {
    if(!fa.count(x) || !fa.count(y)) return false;
    return fa[x] == fa[y];
}
int isparent(int pre, int nxt) {
    if(!fa.count(nxt)) return false;
    return pre == fa[nxt];
}
int isson(int pre, int nxt, int f) {
    return son(pos[pre], f) == pos[nxt];
}
int issamelevel(int x, int y) {
    return dth[x] == dth[y];
}
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cerr << i << endl;
        if(root == -1) {
            root = newNode(x);
            dth[root] = 1;
        } else {
            cerr << root << endl;
            cerr << val(root) << endl;
            Insert(x, root, 1);
        }
    }
    int q;
    cin >> q;
    while(q--) {

    }
}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    work();
    return 0;
}