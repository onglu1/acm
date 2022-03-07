//
// Created by onglu on 2022/2/25.
//

#include <bits/stdc++.h>

#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
#define int long long
using namespace std;
//const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
const int N = 5009;
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
    int x;
    cin >> x;

    if(x < (1ll << 31) && x >= -(1ll << 31)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}