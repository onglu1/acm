//
// Created by onglu on 2022/4/20.
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
int a[2], b[2];
//double bow(int a, int b) {
//    return sqrt(a * a + b * b);
//}
void work() {
    cin >> a[0] >> a[1] >> b[0] >> b[1];
    static int cnt = 0;
    cnt++;
    cout << fixed << setprecision(7);
    cout << "Case " << cnt << ": ";
    double ans = 1e18;
    for(int S = 0; S < 4; S++) {
        int i = S & 1;
        int j = S >> 1;
        if(a[i] > b[j]) {
            ans = min(ans, a[0] * a[1] + b[0] * b[1] + (a[i] - b[j]) * b[1 - j] / 2.0);
        } else {
            ans = min(ans, a[0] * a[1] + b[0] * b[1] + (b[j] - a[i]) * a[1 - i] / 2.0);
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