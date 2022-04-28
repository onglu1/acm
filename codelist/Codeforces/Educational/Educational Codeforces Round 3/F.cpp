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
int n, m, a[N];
struct node {
    int x, t, id;
};
vector<node >v;
int tree[N];
int pos[N], cnt[N], len[N], id[N];
void update(int rt) {
    tree[rt] = max(tree[lson], tree[rson]);
}
void build(int l, int r, int rt) {
    if(l == r) {
        tree[rt] = pos[l] + len[l];
        return ;
    }
    build(l, Mid, lson);
    build(Mid + 1, r, rson);
    update(rt);
}
void modify(int l, int r, int rt, int pos, int x) {
    if(l == r) return (void) (tree[rt] = x);
    if(pos <= Mid) modify(l, Mid, lson, pos, x);
    else modify(Mid + 1, r, rson, pos, x);
    update(rt);
}
int query(int l, int r, int rt, int L, int R) {
    if(L <= l && r <= R) return tree[rt];
    int ans = -1;
    if(L <= Mid) ans = max(ans, query(l, Mid, lson, L, R));
    if(Mid <  R) ans = max(ans, query(Mid + 1, r, rson, L, R));
    return ans;
}
map<int, pair<int, int> > M;
int check(int x, int p) {
    return query(1, n, 1, 1, x) >= p;
}
void work() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int x, t;
        cin >> x >> t;
        v.push_back({x, t, i});
    }
    std::sort(v.begin(), v.end(), [] (const node &a, const node &b) {
        return a.x < b.x;
    });
    for(int i = 1; i <= n; i++) {
        id[v[i - 1].id] = i;
        pos[i] = v[i - 1].x;
        cnt[i] = 0;
        len[i] = v[i - 1].t;
    }
    build(1, n, 1);
    for(int i = 1; i <= m; i++) {
        int x, t;
        cin >> x >> t;
        int rlimit = upper_bound(pos + 1, pos + 1 + n, x) - pos - 1;
        int l = 1, r = rlimit;
        while(l <= r) {
            if(check(Mid, x)) r = Mid - 1;
            else l = Mid + 1;
        }
        if(l > rlimit) {
            if(!M.count(x)) M[x] = {t, 1};
            else {
                M[x].first += t;
                M[x].second += 1;
            }
        } else {
            cnt[l] += 1;
            len[l] += t;
//            if(l == 5) cout << x << " " << pos[l] << " " << len[l] << endl;
            auto it = M.lower_bound(pos[l]);
            while(it != M.end() && it->first <= pos[l] + len[l]) {
//                if(l == 5) cout << it->first << " " << it->second << " " << pos[l] << " " << len[l] << endl;
                len[l] += it->second.first;
                cnt[l] += it->second.second;
                M.erase(it);
                it = M.lower_bound(pos[l]);
            }
            modify(1, n, 1, l, pos[l] + len[l]);
        }
    }
//    cout << id[8] << endl;
    for(int i = 1; i <= n; i++) {
        cout << cnt[id[i]] << " " << len[id[i]] << endl;
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