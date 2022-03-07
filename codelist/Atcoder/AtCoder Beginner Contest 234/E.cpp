#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int n, x;
char c[209];
signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c;
    n = strlen(c);
    for(int i = 0; i < n; i++) {
        x = x * 10 + c[i] - '0';
    }
    if(n == 1 || n == 2) {
        cout << c << endl;
    } else {
        int ans = 1;
        for(int i = 1; i <= n; i++) ans = ans * 10;
        for(int i = 0; i < 10; i++) {
            for(int j = -9; j <= 9; j++) {
                int t = i, now = 0;
                int f = 1;
                for(int k = 1; k <= n; k++) {
                    if(t > 9 || t < 0) {
                        f = 0;
                        break;
                    }
                    now = now * 10 + t;
                    t = t + j;
                }
//                if(i == 1 && j == 4) cout << f << endl;
                if(f && now >= x) {
                    ans = min(ans, now);
                }
            }

        }
        cout << ans << endl;
    }
    return 0;
}