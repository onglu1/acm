//
// Created by onglu on 2022/4/1.
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
const int N = 1e7 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, a[N];
int mu[N], p[N], g[N];
vector<int> pri;
void Init() {
    mu[1] = 1;
    p[1] = 1;
    for(int i = 2; i < N; i++) {
        if(!p[i]) pri.push_back(i), mu[i] = -1;
        for(int j = 0; pri[j] * i < N; j++) {
            p[pri[j] * i] = 1;
            if(i % pri[j] == 0) mu[pri[j] * i] = 0;
            else mu[pri[j] * i] = mu[pri[j]] * mu[i];
            if(i % pri[j] == 0) break;
        }
    }
    for(auto i : pri) {
        for(int j = i; j < N; j += i) {
            g[j] += mu[j / i];
        }
    }
    for(int i = 1; i < N; i++) {
        g[i] += g[i - 1];
    }
}
void work() {
    cin >> n >> m ;
    int t = min(n, m);
    int ans = 0;
    for(int i = 1; i <= t; i++) {
        int j = min(n / (n / i), m / (m / i));
        ans += (n / i) * (m / i) * (g[j] - g[i - 1]);
        i = j;
    }
    cout << ans << endl;
    return ;
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
    Init();
//    return 0;
    while (Case--) work();
    return 0;
}