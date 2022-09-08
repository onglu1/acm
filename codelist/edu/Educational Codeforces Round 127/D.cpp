//
// Created by onglu on 2022/4/22.
//

#include <bits/stdc++.h>
#define int long long
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
int n, m, a[N];

void work() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int minn = a[1], maxn = a[1];
    int sum = 0;
    for(int i = 2; i <= n; i++) {
        minn = min(minn, a[i]);
        maxn = max(maxn, a[i]);
        sum += abs(a[i] - a[i - 1]);
    }
    if(minn > 1) {
        sum += min({minn - 2 + abs(a[1] - (minn - 1)), minn - 2 + abs(a[n] - (minn - 1)), (minn - 1) * 2});
    }
    if(maxn < m) {
        sum += min({m - maxn - 1 + abs(a[1] - (maxn + 1)), m - maxn - 1 + abs(a[n] - (maxn + 1)), (m - maxn) * 2});
    }
    cout << sum << endl;
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