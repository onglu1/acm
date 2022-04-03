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
#define int long long
using namespace std;
const int N = 5e4 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N];
int mu[N], p[N], f[N];
vector<int> pri;
void Init() {
    p[1] = 1;
    mu[1] = 1;
    for(int i = 2; i < N; i++) {
        if(!p[i]) {
            pri.push_back(i);
            mu[i] = -1;
        }
        for(int j = 0; j < pri.size() && pri[j] * i < N; j++) {
            p[pri[j] * i] = 1;
            if(i % pri[j] == 0) {
                mu[pri[j] * i] = 0;
                break;
            } else mu[pri[j] * i] = mu[pri[j]] * mu[i];
        }
    }
    for(int i = 2; i < N; i++) {
        mu[i] += mu[i - 1];
    }
    for(int t = 1; t < N; t++) {
        for(int i = 1; i <= t; i++) {
            int j = min(t, t / (t / i));
            f[t] += t / i * (j - i + 1);
            i = j;
        }
    }
}
void work() {
    cin >> n >> m;
    int ans = 0;
    for(int i = 1; i <= min(n, m); i++) {
        int j = min({min(n, m), n / (n / i), m / (m / i)});
        ans += f[n / i] * f[m / i] * (mu[j] - mu[i - 1]);
        i = j;
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
    int Case = 0;
    Init();
    for(int i = 1; i <= 100; i++) {
        cout << f[i] << " \n"[i % 10 == 0];
    }
//    cin >> Case;
//    while (Case--) work();
    return 0;
}