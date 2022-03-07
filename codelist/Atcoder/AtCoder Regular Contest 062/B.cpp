#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e5 + 1009;
char c[N];

signed main() {
//#ifndef ONLINE_JUDGE
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);
//#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c;
    int n = strlen(c), ans = 0;
    for(int i = 1; i <= n; i++) {
        if(i & 1) {
            if(c[i - 1] == 'p') ans--;
        } else {
            if(c[i - 1] == 'g') ans++;
        }
    }
    cout << ans << endl;
    return 0;
}