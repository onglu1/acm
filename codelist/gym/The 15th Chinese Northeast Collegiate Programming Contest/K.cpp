//
// Created by onglu on 2022/5/18.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, k, pre[N], siz[N];
map<int, int> M;
struct node {
    int x, y, w;
} a[N];
int fid(int x) {
    return pre[x] == x ? x : pre[x] = fid(pre[x]);
}
int ans = 0;
void work() {
    ans  = 0;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        cin >> a[i].x >> a[i].y >> a[i].w;
    }
    for(int i = 1; i <= n; i++) {
        pre[i] = i;
        siz[i] = 1;
    }
    M.clear();
    sort(a + 1, a + 1 + m, [](const node &a, const node &b) {
        return a.w > b.w;
    });
    for(int i = 1; i <= m; ) {
        int j = i;
        while(j <= m && a[j].w == a[i].w) {
            if(fid(a[j].x) != fid(a[j].y)) {
                ans -= siz[fid(a[j].x)] * (siz[fid(a[j].x)] - 1) / 2;
                ans -= siz[fid(a[j].y)] * (siz[fid(a[j].y)] - 1) / 2;
                siz[fid(a[j].x)] += siz[fid(a[j].y)];
                pre[fid(a[j].y)] = fid(a[j].x);
                ans += siz[fid(a[j].x)] * (siz[fid(a[j].x)] - 1) / 2;
            }
            j += 1;
        }
        M[a[i].w] = ans;
        i = j;
    }
    for(int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        if(M.lower_bound(x) == M.end()) cout << 0 << endl;
        else cout << M.lower_bound(x)->second << endl;
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
   cin >> Case;
    while(Case--) work();
    return 0;
}