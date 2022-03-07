#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int n;
signed main() {
//#ifndef ONLINE_JUDGE
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);
//#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int x, y;
    cin >> x >> y;
    for(int i = 2; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        int ta, tb;
        int t = max((x - 1) / a + 1, (y - 1) / b + 1);
        x = a * t; y = b * t;
    }
    cout << x + y << endl;
    return 0;
}