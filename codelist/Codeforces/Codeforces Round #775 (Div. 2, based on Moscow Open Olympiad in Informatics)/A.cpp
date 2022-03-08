//
// Created by onglu on 2022/3/8.
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
    cin >> n;
    int pre = -1, nxt = -1;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(x == 0) {
            if(pre == -1) pre = i;
            nxt = i;
        }
    }
    if(nxt == -1 || pre == -1) cout << 0 << endl;
    else cout << nxt + 1 - (pre - 1) << endl;
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
    return 0;
}