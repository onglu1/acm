//
// Created by onglu on 2022/3/2.
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
const int mod = 100000007;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N];
string s;
int f[N], g[N];
void work() {
    int ans = 1;
    int cnt = 1, num = s[0] - '0';
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == s[i - 1]) cnt++;
        else {
            if(num == 8 || num == 0) {
                ans = ans * g[cnt] % mod;
            } else {
                ans = ans * f[cnt] % mod;
            }
            num = s[i] - '0';
            cnt = 1;
        }
    }
    if(num == 8 || num == 0) {
        ans = ans * g[cnt] % mod;
    } else {
        ans = ans * f[cnt] % mod;
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
    int sum1 = 1, sum2 = 1;
    f[0] = g[0] = 1;
    for(int i = 1; i < N; i++) {
        for(int j = 1; j <= 5 && i - j >= 0; j++) {
            f[i] = (f[i] + f[i - j]) % mod;
        }
        for(int j = 1; j <= 3 && i - j >= 0; j++) {
            g[i] = (g[i] + g[i - j]) % mod;
        }
    }
    for(int i = 0; i < N; i++) {
        if(i - 5 > 0) f[i] = (f[i] + f[i - 5]) % mod;
        if(i - 3 >   0) g[i] = (g[i] + g[i - 3]) % mod;
    }

//    cout << f[2] << endl;
    while(cin >> s) {
        if(s == "#") break;
        work();
    }
    return 0;
}
/*
 * f[n] = f[n - 5] + f[n - 10] + ...
 *
 */