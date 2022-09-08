//
// Created by onglu on 2022/5/30.
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
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
const int mod = 1e9 + 7;
int n, m, a[N], b[N], c[N];
void work() {
    cin >> n >> m;
    memset(a, 0, sizeof(int) * (n + 10));
    memset(b, 0, sizeof(int) * (n + 10));
    memset(c, 0, sizeof(int) * (n + 10));
    for(int i = 1; i <= m; i++) {
        int t, x;
        cin >> t >> x;
        if(t == 1) a[x] += 1;
        else if(t == 2) b[x] += 1;
        else if(t == 3) {
            c[x] += 2;
            (b[x] += (mod - 1)) %= mod;
        }
    }
    for(int i = 1; i <= n; i++) (a[i] += a[i - 1]) %= mod;
    for(int k = 0; k < 2; k++)
        for(int i = 1; i <= n; i++) (b[i] += b[i - 1]) %= mod;
    for(int k = 0; k < 3; k++)
        for(int i = 1; i <= n; i++) (c[i] += c[i - 1]) %= mod;
    for(int i = 1; i <= n; i++) {
        cout << (a[i] + b[i] + c[i]) % mod << " ";
    }
    cout << endl;
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
    while(Case--) work();
    return 0;
}