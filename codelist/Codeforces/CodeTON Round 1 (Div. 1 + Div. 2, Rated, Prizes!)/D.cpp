//
// Created by onglu on 2022/3/24.
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
//const int N = 309
int n, m, a[N];

void work() {
    int p = 2;
    cin >> n;
    while(n % 2 == 0) n /= 2, p *= 2;
    if(n > 1) {
        if(n < p) swap(n, p);
        cout << p << endl;
    } else {
        cout << -1 << endl;
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
  cin >> Case;
    while (Case--) work();
    return 0;
}