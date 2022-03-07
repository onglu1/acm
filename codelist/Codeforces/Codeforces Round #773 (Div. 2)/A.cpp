//
// Created by onglu on 2022/2/27.
//

#include <bits/stdc++.h>
#define int long long
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
//const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
const int N = 5009;
//const int N = 309
int n, m, x[N], y[N];
double dis(int i, int j) {
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}
void work() {
    for(int i = 1; i <= 3; i++) {
        cin >> x[i] >> y[i];
    }
    int ans = 0;
    for(int i = 1; i <= 3; i++) {
        if(y[i] == y[i % 3 + 1] && y[i] != 0 && abs(y[1 + 2 + 3 - i - (i % 3 + 1)]) < abs(y[i])) {
            ans += abs(x[i % 3 + 1] - x[i]);
        }
    }
    cout << ans << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    int Case = 0;
    cin >> Case;
    while (Case--) work();
    return 0;
}