//
// Created by onglu on 2022/3/1.
//

#include <bits/stdc++.h>

#define endl '\n'
#define all(a) a.begin(), a.end()
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2e6 + 1009;

//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m;
struct node {
    vector<int> v;
    int w;
} a[N];
struct Trie{
    int tot = 0, cnt[1 << 10];
    unordered_map<int, int> child[1 << 10];
    void Insert(vector<int> &v, int x) {
        int t = 0;
        for(auto i : v) {
            if(child[t].count(i) == 0)
                child[t][i] = ++tot;
            t = child[t][i];
        }
        cnt[t] += x;
    }
    int query(vector<int> &v) {
        int t = 0;
        for(auto i : v) {
            if(child[t].count(i) == 0)
                return 0;
            t = child[t][i];
        }
        return cnt[t];
    }
} trie;
void Insert(vector<int> &v, int x) {
    for(int i = 0; i < (1 << v.size()); i++) {
        vector<int> t;
        for(int j = 0; j < m; j++) {
            if(i >> j & 1) {
                t.push_back(v[j]);
            }
        }
        trie.Insert(t, x);
    }
}
int query(vector<int> &v) {
    int ans = 0;
    for(int i = 0; i < (1 << v.size()); i++) {
        int cnt = 0;
        vector<int> t;
        for(int j = 0; j < m; j++) {
            if(i >> j & 1) {
                t.push_back(v[j]);
                cnt++;
            }
        }
        ans += ((cnt & 1) ? 1 : -1) * trie.query(t);
    }
    return ans;
}
void work() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            a[i].v.push_back(x);
        }
        sort(all(a[i].v));
        cin >> a[i].w;
    }
    sort(a + 1, a + 1 + n, [](const node &a, const node &b) {
        return a.w > b.w;
    });
    int r = n, ans = 0;
    for(int i = 1; i <= n; i++) {
        Insert(a[i].v, 1);
    }
    cout << query(a[n].v) << endl;
    for(int l = 1; l <= n; l++) {
        Insert(a[l].v, -1);
        while(r > l && trie.query(a[l].v) < (r - l) - 1) {
            Insert(a[r].v, -1);
            r--;
        }
        if(trie.query(a[l].v) == (r - l) - 1)
            ans = max(ans, a[l].w + a[r].w);
    }
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
    while (Case--) work();
    return 0;
}