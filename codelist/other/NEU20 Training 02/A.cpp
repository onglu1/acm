#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int n;

void work() {
    int t = 0, cnt = 0;
    cin >> t;
    for(int i = 1; i <= min(6, t); i++) {
        int y = t - i;
        if(y >= i & y <= 6) {
            cnt++;
        }
    }
    cout << cnt << endl;
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