#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e5 + 1009;
int n;
char c[N];
signed main() {
//#ifndef ONLINE_JUDGE
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);
//#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c;
    n = strlen(c);
    int ans = 1;
    for(int i = 1; i < n; i++) {
        if(c[i] != c[i - 1]) {
            ans++;
        }
    }
    cout << ans - 1 << endl;
    return 0;
}