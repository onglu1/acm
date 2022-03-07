#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e5 + 1009;
int n, m, a[N], b[N];
int pos[N];
int tree[N];
void add(int x, int y) {
    for( ; x < N; x += x & -x) {
        tree[x] = max(tree[x], y);
    }
}
int query(int x) {
    int ans = 0;
    for( ; x; x -= x & -x)
        ans = max(ans, tree[x]);
    return ans;
}
vector<int> v, p[N];
int getlis(vector<int> &v) {
    int len = 0;
    for(auto x : v) {
        int t = query(x - 1) + 1;
        add(x, t);
        len = max(len, t);
    }
    return len;
}
signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j += i) {
            p[i].push_back(pos[j]);
        }
        sort(p[i].begin(), p[i].end());
        reverse(p[i].begin(), p[i].end());
    }
    for(int i = 1; i <= n; i++) {
        for(auto x : p[a[i]]) {
            v.push_back(x);
        }
//        for(int j = a[i]; j <= n; j += a[i]) {
//            v.push_back(pos[j]);
//        }
    }
    cout << getlis(v) << endl;
    return 0;
}