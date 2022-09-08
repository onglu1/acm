//
// Created by onglu on 2022/5/9.
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
int n, m, a[N], b[N], vis[N], pos[N];
int check(int x) {
    int len = 0;
    while(!vis[x]) {
        vis[x] = 1;
        x = pos[b[x]];
        len += 1;
    }
    return len;
}
int l, r, f;
int nxt() {
    f ^= 1;
    if(f) return l++;
    else return r--;
}
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) pos[a[i]] = i;
    memset(vis, 0, sizeof(int) * (n + 10));
    vector<int> v;
    for(int i = 1; i <= n; i++) if(!vis[i]) {
        v.push_back(check(i));
    }
    std::sort(v.begin(), v.end());
//    std::reverse(v.begin(), v.end());
    l = 1, r = n, f = 0;
    int p = 0, ans = 0;
    for(auto x : v) {
        if(x == 1) continue;
        int st = nxt();
        int now = st;
        for(int i = 1; i < (x / 2) * 2; i++) {
            int tt = nxt();
            ans += abs(tt - now);
            now = tt;
        }
        ans += abs(now - st);
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
    cin >> Case;
    while (Case--) work();
    return 0;
}