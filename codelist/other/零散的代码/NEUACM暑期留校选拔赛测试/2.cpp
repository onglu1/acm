//
// Created by onglu on 2022/5/29.
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
int n, m, a[N];

void work() {
    int is0 = false;
    int ans = 0, prod = 1;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(x < 0) {
            ans += (-1 - x);
            prod *= -1;
        } else if(x > 0) {
            ans += (x - 1);
        } else {
            ans += 1;
            is0 = true;
        }
    }
    if(is0) {
        cout << ans << endl;
    } else {
        cout << ((prod == -1) ? ans + 2 : ans) << endl;
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
//    cin >>
    while(cin >> n) work();
    return 0;
}