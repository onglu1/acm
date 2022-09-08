//
// Created by onglu on 2022/4/28.
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
const int mod = 1e9 + 7;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, a[N];

void work() {
    cin >> n >> m;
    int ans = 0;
    if(m > n) {
        ans = n % mod * ((m - n) % mod) % mod;
        m = n;
    }
    ans = (ans + (n % mod) * (m % mod) % mod) % mod;
    int j;
    for(int i = 1; i <= m; i = j + 1) {
        j = min(n / (n / i), m);
        int s;
        if((i + j) % 2 == 0) s = (i + j) / 2 % mod * ((j - i + 1) % mod) % mod;
        else s = (j - i + 1) / 2 % mod * ((i + j) % mod) % mod;
        ans = (ans - s * ((n / i) % mod) % mod) % mod;
    }
    cout << (ans + mod) % mod << endl;

}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
//    cin >> Case;
    while (Case--) work();
    return 0;
}