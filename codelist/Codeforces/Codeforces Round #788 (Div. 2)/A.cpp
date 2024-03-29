//
// Created by onglu on 2022/5/6.
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
//const int N = 309;
int n, m, a[N];

int work() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] < 0) {
            a[i] = -a[i];
            cnt++;
        }
    }
    for(int i = 1; i <= cnt; i++) a[i] = -a[i];
    for(int i = 2; i <= n; i++) if(a[i] < a[i - 1]) return false;
    return true;
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
    while (Case--) cout << (work() ? "YES" : "NO") << endl;
    return 0;
}