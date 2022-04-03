//
// Created by onglu on 2022/3/19.
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
//const int N = 309
int n, m, k, a[N];
vector<double> v, p;
void work() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        int total = 0, maxn = -1, minn = 1000;
        p.clear();
        for(int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            total += x;
            maxn = max(maxn, x);
            minn = min(minn, x);
        }
        v.push_back((total - maxn - minn) * 1.0 / (m - 2));
    }
    sort(rall(v));
    for(int i = k - 1; i >= 0; i--) {
        printf("%.3f%c", v[i], " \n"[i == 0]);
    }
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
//  cin >> Case;
    while (Case--) work();
    return 0;
}