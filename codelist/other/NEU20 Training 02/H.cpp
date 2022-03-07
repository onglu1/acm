#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int n, k;

void work() {
    int cnt = 0;
    cin >> n >> k;
    for(int i = 1; i <= k; i++) {
        for(int j = i; j <= n; j += k) {
            cnt++;
            cout << j << (cnt == n ? '\n' : ' ');
        }
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    work();
    return 0;
}