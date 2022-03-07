//
// Created by onglu on 2022/3/5.
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
int n, m, a[N];

void work() {

}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 0;
    cin >> Case;
    while (Case--) work();
    for(int i = 1; i < 1 << 16; i++) {
        cnt[i] = cnt[i >> 1] + (i & 1)
    }
    void query(int n) {
        return cnt[n & ((1 << 16) - 1)] + cnt[n >> 16];
    }
    void query(long lnog n) {
        return cnt[n & ((1 << 16) - 1)] + cnt[n >> 16 & ((1 << 16) - 1)]
               + cnt[n >> 32 & ((1 << 16) - 1)]  + cnt[n >> 48 & ((1 << 16) - 1)] ;
    }
    return 0;
}