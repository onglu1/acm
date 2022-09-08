//
// Created by onglu on 2022/9/2.
//

#include <bits/stdc++.h>

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
using namespace std;
const int N = 2e6 + 1009;
struct SAM {
    int ch[N << 1][26], fail[N << 1], siz[N << 1], len[N << 1], endpos[N << 1];
    int p[N << 1];
    int num = 1, last = 1;
    void insert(int c, int pos) {
        int now = ++num, node = last;
        p[pos] = now;
        len[now] = len[last] + 1;
        siz[now] = 1;
        endpos[now] = pos;
        while(node && !ch[node][c]) ch[node][c] = now, node = fail[node];
        if(!node) fail[now] = 1;
        else {
            int cur = ch[node][c];
            if(len[cur] == len[node] + 1) fail[now] = cur;
            else {
                int clone = ++num;
                for(int i = 0; i < 26; i++) ch[clone][i] = ch[cur][i];
                len[clone] = len[node] + 1;
                fail[clone] = fail[cur];
                while(node && ch[node][c] == cur)
                    ch[node][c] = clone, node = fail[node];
                fail[now] = fail[cur] = clone;
            }
        }
        last = now;
    }
} sam;
struct SGT {
    int limit = 0;
    int tree[N * 4], lzt[N * 4];
    void setLimit(int t) {limit = t;}
    void update(int rt) {tree[rt] = tree[lson] + tree[rson];}
    void pushdown(int l, int r, int rt) {
        if(lzt[rt] == 0) return;
        tree[lson] += lzt[rt] * (Mid - l + 1); lzt[lson] += lzt[rt];
        tree[rson] += lzt[rt] * (r - Mid); lzt[rson] += lzt[rt];
        lzt[rt] = 0;
    }
    void modify(int l, int r, int rt, int L, int R, int v) {
        if(L <= l && r <= R) {
            tree[rt] += (r - l + 1) * v;
            lzt[rt] += v;
            return ;
        }
        pushdown(l, r, rt);
        if(L <= Mid) modify(l, Mid, lson, L, R, v);
        if(Mid <  R) modify(Mid + 1, r, rson, l, R, v);
        update(rt);
    }
    int query(int l, int r, int rt, int L, int R) {
        if(L <= l && r <= R) return tree[rt];
        pushdown(l, r, rt);
        int ans = 0;
        // if(L <= Mid) ans += query(l, Mid, lson, L, R);
        // if(Mid <  R) ans += query(Mid + 1, r, rson, L, R);
        // return ans;
        if(R <= Mid) return query(l, Mid, lson, L, R);
        if(Mid < L) return query(Mid + 1, r, rson, L, R);
        return query(l, Mid, lson, L, R) + query(Mid + 1, r, rson, L, R);
    }
    int tmp[N];
    void state() {
        cout << "true : " ; for(int i = 1; i <= limit; i++) cout << tmp[i] << " " ; cout << endl;
        cout << "false : " ; for(int i = 1; i <= limit; i++) cout << query(1, limit, 1, i, i) << " " ; cout << endl;
    }
    int query(int l, int r) {
        cout << "query : " << l << " " << r << " " << limit << endl;
        state();
        int ans = 0;
        for(int i = l; i <= r; i++) ans += tmp[i];
        // cout << "should return : " << ans << " " << "return : " << query(1, limit, 1, l, r) << endl;
        // return ans;
        // l += 2; r += 2;
        return query(1, limit, 1, l, r);
    }
    void modify(int l, int r, int v) {
        if(l > r) return ;
        cout << "modify : " << l << " " << r << " " << v << " " << limit << endl;
        // l += 2; r += 2;
        for(int i = l; i <= r; i++) tmp[i] += v;
        modify(1, limit, 1, l, r, v);
        state();
    }
} sgt;
struct LCT {
    int fa[N], ch[N][2], val[N], tag[N], tmp[N];
    bool isroot(int x) {return !fa[x] || ch[fa[x]][0] != x && ch[fa[x]][1] != x;}
    void pushtag(int x, int y) {
        if(x == 0) return;
        val[x] = y;
        tag[x] = y;
    }
    void pushdown(int x) {
        if(tag[x]) {
            if(ch[x][0]) pushtag(ch[x][0], tag[x]);
            if(ch[x][1]) pushtag(ch[x][1], tag[x]);
            tag[x] = 0;
        }
    }
    void rotate(int x) {
        int y = fa[x], w = ch[y][1] == x;
        ch[y][w] = ch[x][w ^ 1];
        if(ch[x][w ^ 1]) fa[ch[x][w ^ 1]] = y;
        if(fa[y]) {
            int z = fa[y];
            if(ch[z][0] == y) ch[z][0] = x; else if(ch[z][1] == y) ch[z][1] = x;
        }
        fa[x] = fa[y]; fa[y] = x; ch[x][w ^ 1] = y;
    }
    void splay(int x) {
        int s = 1, i = x, y; tmp[1] = i;
        while(!isroot(i)) tmp[++s] = i = fa[i];
        while(s) pushdown(tmp[s--]);
        while(!isroot(x)) {
            y = fa[x];
            if(!isroot(y)) {
                if((ch[fa[y]][0] == y) ^ (ch[y][0] == x)) rotate(x);
                else rotate(y);
            }
            rotate(x);
        }
    }
    void access(int x, int v) {
        int y;
        for(y = 0; x; y = x, x = fa[x]) {
            splay(x);
            ch[x][1] = y;
            if(val[x]) {
                // cout << " " << x << " " << val[x] << " " << sam.len[x] << " " << (val[x] - sam.len[x] + 1) << " " << ( val[x] - sam.len[fa[x]]) << " " << -1 << endl;
                sgt.modify(val[x] - sam.len[x] + 1, val[x] - sam.len[fa[x]], -1);
            }
        }
        // cout << 1 << " " << v << " " << 1 << endl;
        pushtag(y, v); sgt.modify(1, v, 1);
    }
} lct;
// using namespace SAM;
string s;
vector<pair<int, int> > v[N];
int n, ans[N];
void work() {
    cin >> s;
    cin >> n;
    sgt.setLimit(s.size());
    for(int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        v[r].push_back({i, l});
    }
    for(int i = 0; i < s.size(); i++) sam.insert(s[i] - 'a', i + 1);
    for(int i = 2; i <= sam.num; i++) lct.fa[i] = sam.fail[i];
    for(int i = 1; i <= s.size(); i++) {
        lct.access(sam.p[i], i);
        for(auto item : v[i]) {
            // cout << "q " << item.second << " " << i << endl;
            ans[item.first] = sgt.query(item.second, i);
        }
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << endl;
}

signed main() {
// #ifdef LOCAL
//     freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
//     freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
// #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
    // cin >> Case;
    while(Case--) work();
    return 0;
}