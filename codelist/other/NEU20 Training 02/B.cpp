#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 1e5 + 1009;
vector<int> pos[N];
int n, k, m;
int a[N], vis[N], h[N];
void work() {
    memset(h, 0, sizeof(int) * (n + 10));
    memset(a, 0, sizeof(int) * (n + 10));
    memset(vis, 0, sizeof(int) * (k + 10));
    cin >> n >> k >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= k; i++) {
        pos[i].clear();
    }
    for(int i = 1; i <= n; i++) {
        pos[a[i]].push_back(i);
    }
    for(int i = 1; i <= k; i++) {
        int p = 0;
        for(long long j : pos[i]) {
            if(p == 1) {
                h[j]++;
            }
            p ^= 1;
        }
        for(long long j : pos[i]) {
            if(p == 1) {
                h[j]++;
            }
            p ^= 1;
        }
    }
    for(int i = 1; i <= n; i++) {
        h[i] *= m / (2 * n);
    }
    m %= 2 * n;
    for(int i = 1; i <= m; i++) {
        int j = (i - 1) % n + 1;
        if(vis[a[j]] == 1) {
            h[j]++;
        }
        vis[a[j]] ^= 1;
    }
    for(int i = 1; i <= n; i++) {
        cout << h[i] << (i == n ? '\n' : ' ');
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case = 0;
    cin >> Case;
    while (Case--) work();
    return 0;
}