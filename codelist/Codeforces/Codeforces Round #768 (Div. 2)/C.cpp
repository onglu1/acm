//
// Created by onglu on 2022/4/14.
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
int n, k, a[N];
int num[N], vis[N];
int bit = 0;
void work() {
    cin >> n >> k;
    memset(vis, 0, sizeof(int) * (n + 5));
    if(k == n - 1) {
        if(n <= 4) {
            cout << -1 << endl;
            return ;
        }
        vis[n - 1] = 1; vis[n - 1 - 1] = 1;
        vis[1] = vis[3] = 1;
        vis[n - 1 - 3] = vis[0] = 1;
        cout << n - 1 << " " << n - 1 - 1 << endl;
        cout << 1 << " " << 3 << endl;
        cout << n - 1 - 3 << " " << 0 << endl;
    } else {
        vis[n - 1] = 1; vis[k] = 1;
        vis[0] = vis[n - 1 - k] = 1;
        cout << k << " " << n - 1 << endl;
        if(k != 0) cout << 0 << " " << n - 1 - k << endl;
    }
    for(int i = 0; i < n; i++) if(!vis[i]) {
        cout << i << " " << n - 1 - i << endl;
        vis[i] = vis[n - 1 - i] = 1;
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
    while (Case--) work();
    return 0;
}