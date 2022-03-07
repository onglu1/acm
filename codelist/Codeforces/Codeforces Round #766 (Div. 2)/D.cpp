#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 1e6;
int n, cnt[N + 5];

void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) if(!cnt[i]) {
        int t = -1;
        for(int j = i; j <= N; j += i) if(cnt[j]) {
            if(t == -1) t = j;
            else t = __gcd(t, j);
        }
        if(t == i) {
            ans++;
        }
    }
    cout << ans << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case = 1;
    while (Case--) work();
    return 0;
}