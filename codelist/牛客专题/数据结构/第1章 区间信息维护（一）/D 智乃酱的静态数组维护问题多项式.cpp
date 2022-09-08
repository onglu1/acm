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
const int mod = 1e9 + 7;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, q, a[N], d[N];
int tt = 5;
int f(int x, const vector<int> &c) {
    int sum = 0;
    for(int i = (int)c.size() - 1; i >= 0; i--) {
        sum = (sum * x % mod + c[i]) % mod;
    }
    return sum;
}
// void printd() {
//     for(int i = 0; i <= 5; i++) {
//         for(int j = 1; j <= n; j++) {
//             cout << d[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }
void modify(int l, int r, const vector<int> &c) {
    vector<int> dif(c.size() + 5);
    for(int i = 0; i < dif.size(); i++) {
        dif[i] = f(i + 1, c);
    }
    for(int t = 0; t <= tt; t++) {
        for(int i = (int) dif.size() - 1; i > 0; i--) {
            dif[i] = dif[i] - dif[i - 1];
        }
    }
    // cout << "dif : ";
    // for(auto x : dif) {
    //     cout << x << " ";
    // }
    // cout << endl;
    for(int i = 0; i < dif.size() && l + i <= n; i++) {
        (d[l + i] += dif[i]) %= mod;
    }
    // printd();
    for(int i = 0; i < dif.size(); i++) {
        dif[i] = f(i + r - l + 2, c);
    }
    for(int t = 0; t <= tt; t++) {
        for(int i = (int) dif.size() - 1; i > 0; i--) {
            dif[i] = dif[i] - dif[i - 1];
        }
    }
    // cout << "rdif : ";
    // for(auto x : dif) {
    //     cout << x << " ";
    // }
    // cout << endl;
    for(int i = 0; i < dif.size() && r + 1 + i <= n; i++) {
        (d[r + 1 + i] += mod - dif[i]) %= mod;
    }
    // printd();

}

void work() {
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        vector<int> c(k + 1);
        for(int j = 0; j <= k; j++) {
            cin >> c[j];
            c[j] = (c[j] % mod + mod) % mod;
        }
        std::reverse(c.begin(), c.end());
        modify(l, r, c);
    }
    // printd();
    for(int i = 0; i <= tt; i++)
        for(int j = 1; j <= n; j++)
            d[j] = (d[j] + d[j - 1]) % mod;
    // for(int i = 0; i <= 5; i++) {
    //     for(int j = 0; j <= i; j++) {
    //         for(int k = 1; k <= n; k++) {
    //             d[i][k] += d[i][k - 1];
    //         }
    //     }
    // }
    for(int i = 1; i <= n; i++) {
        (a[i] += d[i]) %= mod;
        (a[i] += a[i - 1]) %= mod;
    }
    for(int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        cout << ((a[r] - a[l - 1] + mod) % mod + mod) % mod << endl;
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
    // cin >> Case;
    while(Case--) work();
    return 0;
}
/*
10 2 5
1000 1000 1000 100000 1000 1000 10000 10000 10000 100000
1 2 0 100
1 3 2 2 1 1
1 1
2 2
3 3
4 4
5 5
*/