//
// Created by onglu on 2022/5/6.
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
const int mod = 1e9 + 7;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, a[N], b[N], d[N];
int pa[N], vis[N];
int mark(int x) {
    int cnt = 0;
    while(!vis[x]) {
        cnt ++;
        vis[x] = 1;
        x = pa[b[x]];
    }
    return cnt > 1;
}
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) cin >> d[i];
    for(int i = 1; i <= n; i++) {
        pa[a[i]] = i;
    }
    memset(vis, 0, sizeof(int) * (n + 10));
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        if(d[i] && !vis[i]) {
            mark(i);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            ans = ans * (mark(i) ? 2 : 1) % mod;
        }
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