//
// Created by onglu on 2022/3/14.
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
const int N = 5e4 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N], k;
int mu[N], pri[N], f[N], tot = 0;
void init() {
    mu[1] = 1;
    for(int i = 2; i < N; i++) {
        if(!f[i]) {
            mu[i] = -1;
            pri[++tot] = i;
        }
        for(int j = 1; j <= tot && pri[j] * i < N; j++) {
            f[pri[j] * i] = 1;
            if(i % pri[j] == 0) {
                mu[pri[j] * i] = 0;
                break;
            }
            mu[pri[j] * i] = -mu[i];
        }
    }
    for(int i = 1; i < N; i++) mu[i] += mu[i - 1];
}
int solver(int n, int m) {
    if(n <= 0 || m <= 0) return 0;
    int res = 0, j ;
    for(int i = 1; i <= min(n, m); i = j + 1) {
        j = min(n / (n / i), m / (m / i));
        res += (mu[j] - mu[i - 1]) * (n / k / i) * (m / k / i);
    }
    return res;
}
void work() {
    int a, b, c, d;
    cin >> a >> b >> c >> d >> k;
    int ans = solver(b, d) - solver(a - 1, d) - solver(b, c - 1)
              + solver(a - 1, c - 1);
    cout << ans << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int Case;
    cin >> Case;
    while(Case--) work();
    return 0;
}