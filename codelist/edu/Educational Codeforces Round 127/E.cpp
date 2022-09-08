//
// Created by onglu on 2022/4/22.
//

#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (i << 1)
#define rson (i << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
const int mod = 998244353;
int n, m, a[N], f[N];
string val[N];
int len[N];
char c[N];
void work() {
    cin >> n;
    cin >> (c + 1);
    for(int i = 1; i < 1 << n; i++) {
        c[i] = c[i] - 'A' + '0';
    }
    for(int i = (1 << (n - 1)); i < 1 << n; i++) f[i] = 1, len[i] = 1, val[i] = c[i];
    for(int i = (1 << (n - 1)) - 1; i >= 1; i--) {
        len[i] = len[lson] + len[rson] + 1;
        if(val[lson] > val[rson]) val[i] = c[i] + val[lson] + val[rson];
        else val[i] = c[i] + val[rson] + val[lson];
//        if(val[lson] > val[rson]) val[i] = (a[i] << (len[i] - 1)) + (val[lson] << len[rson]) + val[rson];
//        else val[i] = (a[i] << (len[i] - 1)) + (val[rson] << len[rson]) + val[lson];
        if(val[lson] == val[rson]) f[i] = f[lson] * f[rson] % mod;
        else f[i] = f[lson] * f[rson] % mod * 2 % mod;
    }
//    cout << val[6] << " " << val[7] << endl;
    cout << f[1] << endl;
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